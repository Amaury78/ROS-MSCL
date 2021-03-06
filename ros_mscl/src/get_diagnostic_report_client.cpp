#include "ros/ros.h"
#include "std_srvs/Trigger.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "get_diagnostic_report_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<std_srvs::Trigger>("GetDiagnosticReport");
  std_srvs::Trigger srv;


  if (client.call(srv))
  {
      if (srv.response.success)
      {
        ROS_INFO("success");
      }
  }
  else
  {
    ROS_INFO("Failed to call service");
  }
  return 0;
}
