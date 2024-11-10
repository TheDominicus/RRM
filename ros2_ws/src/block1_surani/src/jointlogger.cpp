#include "surani_interface/srv/my_service.hpp" //header file pre srv interface

class JointLogger : public rclcpp::Node{
    service_ = this->create_service<priezvisko_interface::srv::MyService>("my_service",
        std::bind(&JointLogger::my_service_callback, this, std::placeholders::_1, std::placeholders::_2));

    private:
        //deklaracia premennej typu server s cust. interface
        rclcpp::Service<surani_interface::srv::MyService>::SharedPtr service_;
    public:
        //obslužná funkcia pre server
        void my_service_callback(const std::shared_ptr<surani_interface::srv::MyService::Request> request,
            std::shared_ptr<surani_interface::srv::MyService::Response> response);
        
        void JointLogger::my_service_callback(const std::shared_ptr<surani_interface::srv::MyService::Request>
            request, std::shared_ptr<surani_interface::srv::MyService::Response> response){
            float velocity = request->velocity;
            //TODO: vasa funkcionalita
            RCLCPP_INFO(this->get_logger(), "Request received: %f, sending response", request->velocity);
            response->result = true;
            response->message = "Response from joint logger";
        }
}
int main(int argc, char ** argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<JointLogger> logger = std::make_shared<JointLogger>();
    rclcpp::spin(logger); //function that blocks the thread and allows the node to process callbacks
    rclcpp::shutdown();
    
    return 0;
}