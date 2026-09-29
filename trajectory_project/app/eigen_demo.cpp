#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>

int main()
{
    Eigen::Matrix2d matrix;
    matrix << 1.0, 2.0,
              3.0, 4.0;

    Eigen::Vector2d vector;
    vector << 5.0, 6.0;

    Eigen::Vector2d result = matrix * vector;

    std::cout << "矩阵：\n" << matrix << '\n';
    std::cout << "向量：\n" << vector << '\n';
    std::cout << "结果：\n" << result << '\n';

    Eigen::Vector2d point;
    point << 2.0, 1.0;

    Eigen::Matrix2d rotate90;
    rotate90 << 0.0, -1.0,
                1.0,  0.0;

    Eigen::Vector2d rotated_point = rotate90 * point;

    std::cout << "旋转前：\n" << point << '\n';
    std::cout << "旋转后：\n" << rotated_point << '\n';

    Eigen::Vector2d local_origin_in_world;
    local_origin_in_world << 3.0, 4.0;

    Eigen::Vector2d point_in_world =
        rotate90 * point + local_origin_in_world;

    std::cout << "世界坐标：\n"
            << point_in_world << '\n';

    Eigen::Vector3d point_local3d(2.0, 1.0, 1.0);

    Eigen::Matrix3d rotation_z90;
    rotation_z90 << 0.0, -1.0, 0.0,
                    1.0,  0.0, 0.0,
                    0.0,  0.0, 1.0;

    Eigen::Vector3d translation_world3d(3.0, 4.0, 5.0);

    Eigen::Vector3d point_world3d =
        rotation_z90 * point_local3d + translation_world3d;

    std::cout << "三维局部坐标：\n" << point_local3d << '\n';
    std::cout << "三维世界坐标：\n" << point_world3d << '\n';





    Eigen::Isometry3d pose_world_from_local =
        Eigen::Isometry3d::Identity();

    pose_world_from_local.linear() = rotation_z90;
    pose_world_from_local.translation() = translation_world3d;

    Eigen::Vector3d point_via_pose =
        pose_world_from_local * point_local3d;

    std::cout << "位姿矩阵：\n"
            << pose_world_from_local.matrix() << '\n';

    std::cout << "通过位姿计算的世界坐标：\n"
            << point_via_pose << '\n';

    Eigen::Isometry3d pose_local_from_world =
        pose_world_from_local.inverse();

    Eigen::Vector3d recovered_local =
        pose_local_from_world * point_via_pose;

    std::cout << "逆位姿矩阵：\n"
            << pose_local_from_world.matrix() << '\n';

    std::cout << "恢复的局部坐标：\n"
            << recovered_local << '\n';




    Eigen::Isometry3d pose_local_from_tool =
        Eigen::Isometry3d::Identity();

    pose_local_from_tool.translation() =
        Eigen::Vector3d(1.0, 0.0, 0.0);

    Eigen::Vector3d tool_tip_in_tool(0.0, 0.0, 2.0);

    Eigen::Vector3d tool_tip_in_local =
        pose_local_from_tool * tool_tip_in_tool;

    Eigen::Isometry3d pose_world_from_tool =
        pose_world_from_local * pose_local_from_tool;

    Eigen::Vector3d tool_tip_in_world =
        pose_world_from_tool * tool_tip_in_tool;

    std::cout << "工具尖端在末端坐标系：\n"
            << tool_tip_in_local << '\n';

    std::cout << "工具尖端在底座坐标系：\n"
            << tool_tip_in_world << '\n';

    Eigen::Vector3d tool_origin_in_world =
        pose_world_from_tool * Eigen::Vector3d::Zero();

    Eigen::Vector3d recovered_tip_in_tool =
        pose_world_from_tool.inverse() * tool_tip_in_world;

    std::cout << "工具原点在底座坐标系：\n"
            << tool_origin_in_world << '\n';

    std::cout << "换回工具坐标系的尖端：\n"
            << recovered_tip_in_tool << '\n';

    return 0;
}
