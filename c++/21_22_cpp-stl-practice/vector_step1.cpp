#include <iostream>
#include <memory>

class JointData {
public:
    JointData() {
        std::cout << "JointData 对象已创建\n";
    }

    ~JointData() {
        std::cout << "JointData 对象已销毁\n";
    }

    void print() const {
        std::cout << "正在处理关节数据\n";
    }
};

int main() {
    std::cout << "===== unique_ptr 演示 =====\n";

    {
        auto unique_joint =
            std::make_unique<JointData>();

        unique_joint->print();
    }

    std::cout << "unique_ptr 作用域已经结束\n\n";

    std::cout << "===== shared_ptr 演示 =====\n";

    {
        auto owner1 =
            std::make_shared<JointData>();

        std::cout << "当前所有者数量: "
                  << owner1.use_count()
                  << '\n';

        {
            auto owner2 = owner1;

            std::cout << "复制后的所有者数量: "
                      << owner1.use_count()
                      << '\n';

            owner2->print();
        }

        std::cout << "owner2 消失后的所有者数量: "
                  << owner1.use_count()
                  << '\n';
    }

    std::cout << "shared_ptr 作用域已经结束\n";

    return 0;
}