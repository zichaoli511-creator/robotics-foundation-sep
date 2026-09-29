import csv

count = 0

with open("joint_trajectory.csv", newline="", encoding="utf-8") as file:
    reader = csv.DictReader(file)
    print("列名：", reader.fieldnames)

    for row in reader:
        count += 1
        time_s = float(row["time_s"])

        angles = []
        for number in range(1, 7):
            column = f"joint_{number}_rad"
            angles.append(float(row[column]))

        print(f"时间 {time_s:g} 秒，六关节角：{angles}")

print("共读取", count, "个时刻")
