import csv

import matplotlib.pyplot as plt
import numpy as np

time_values = []
angle_rows = []

with open("joint_trajectory.csv", newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)

    for row in reader:
        time_values.append(float(row["time_s"]))

        six_angles = []
        for number in range(1, 7):
            column = f"joint_{number}_rad"
            six_angles.append(float(row[column]))

        angle_rows.append(six_angles)

times = np.array(time_values)
angles = np.array(angle_rows)

print("时间数组形状：", times.shape)
print("关节角数组形状：", angles.shape)

fig, ax = plt.subplots()
ax.plot(times, angles[:, 0], marker="o")
ax.set_xlabel("Time (s)")
ax.set_ylabel("Joint 1 angle (rad)")
ax.set_title("Joint 1 trajectory")
ax.grid(True)

fig.savefig("plots/joint_1.png", dpi=150)
print("图片已保存：plots/joint_1.png")
fig2, ax2 = plt.subplots(figsize=(9, 5))

for index in range(6):
    ax2.plot(
        times,
        angles[:, index],
        marker="o",
        label=f"Joint {index + 1}"
    )

ax2.set_xlabel("Time (s)")
ax2.set_ylabel("Joint angle (rad)")
ax2.set_title("Six-joint trajectory")
ax2.grid(True)
ax2.legend()

fig2.tight_layout()
fig2.savefig("plots/all_joints.png", dpi=150)
print("图片已保存：plots/all_joints.png")

joint_1_angles = angles[:, 0]

angle_changes = np.diff(joint_1_angles)
time_intervals = np.diff(times)
joint_1_velocities = angle_changes / time_intervals

print("第一关节各段平均角速度：")
print(np.round(joint_1_velocities, 2))

interval_midpoints = (times[:-1] + times[1:]) / 2

fig3, ax3 = plt.subplots()
ax3.plot(interval_midpoints, joint_1_velocities, marker="o")
ax3.set_xlabel("Time (s)")
ax3.set_ylabel("Average angular velocity (rad/s)")
ax3.set_title("Joint 1 velocity")
ax3.set_ylim(0, 0.2)
ax3.grid(True)

fig3.tight_layout()
fig3.savefig("plots/joint_1_velocity.png", dpi=150)
print("图片已保存：plots/joint_1_velocity.png")
all_angle_changes = np.diff(angles, axis=0)
all_velocities = all_angle_changes / time_intervals[:, None]

print("六关节速度数组形状：", all_velocities.shape)
print("每行是一段时间内六个关节的平均角速度：")
print(np.round(all_velocities, 2))

fig4, ax4 = plt.subplots(figsize=(9, 5))

for index in range(6):
    ax4.plot(
        interval_midpoints,
        all_velocities[:, index],
        marker="o",
        label=f"Joint {index + 1}"
    )

ax4.set_xlabel("Time (s)")
ax4.set_ylabel("Average angular velocity (rad/s)")
ax4.set_title("Six-joint velocities")
ax4.grid(True)
ax4.legend()

fig4.tight_layout()
fig4.savefig("plots/all_joint_velocities.png", dpi=150)
print("图片已保存：plots/all_joint_velocities.png")
# 第一部分：统计每个关节的最大平均角速度
max_abs_velocities = np.max(np.abs(all_velocities), axis=0)

print("各关节最大平均角速度的绝对值：")
for index in range(6):
    print(f"Joint {index + 1}: {max_abs_velocities[index]:.2f} rad/s")


# 第二部分：找出超过练习阈值的区间
practice_limit = 0.16
over_limit = np.abs(all_velocities) > practice_limit

print("超过练习阈值的区间：")
found = False

for interval_index in range(all_velocities.shape[0]):
    for joint_index in range(all_velocities.shape[1]):
        if over_limit[interval_index, joint_index]:
            found = True
            speed = all_velocities[interval_index, joint_index]
            start = times[interval_index]
            end = times[interval_index + 1]

            print(
                f"Joint {joint_index + 1}: "
                f"{start:g}～{end:g} 秒，"
                f"{speed:.2f} rad/s"
            )

if not found:
    print("没有超出阈值的区间")


# 第三部分：在速度图上标出阈值
ax4.axhline(
    practice_limit,
    color="black",
    linestyle="--",
    label="+0.16 practice limit"
)
ax4.axhline(
    -practice_limit,
    color="gray",
    linestyle="--",
    label="-0.16 practice limit"
)
ax4.legend(ncol=2, fontsize=8)
fig4.tight_layout()
fig4.savefig("plots/velocity_limit_check.png", dpi=150)


# 第四部分：将计算结果写成新的 CSV
header = ["start_s", "end_s"]
for index in range(6):
    header.append(f"joint_{index + 1}_rad_s")

with open("joint_velocity.csv", "w", newline="", encoding="utf-8") as file:
    writer = csv.writer(file)
    writer.writerow(header)

    for interval_index in range(all_velocities.shape[0]):
        values = [
            times[interval_index],
            times[interval_index + 1]
        ]
        values.extend(
            np.round(all_velocities[interval_index], 3).tolist()
        )
        writer.writerow(values)

print("已保存：plots/velocity_limit_check.png")
print("已保存：joint_velocity.csv")
