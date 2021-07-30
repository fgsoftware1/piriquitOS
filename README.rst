Setup                            
====================== ==================================
      Windows(docker)  docker-compose.yml or win-env.cmd
====================== ==================================
      Linux                  sudo bash linux-deps.sh                           
      Linux(docker)                  bash linux-env.sh
====================== ==================================
+-------------------------------------------------------------------------------------------------------------------------------+
|Build                                                                                                                          |
+=======================+=======================================================================================================+
|      Windows(docker)  |  1. run docker container                                                                              |                                                                                                     |
|                       | 2. enter on container shell(if you run win-env.cmd you will auto enter on shell after container run)  |
|                       | 3. write ninja on shell                                                                               |
+-----------------------+-------------------------------------------------------------------------------------------------------+
|      Linux(docker)    |  1. run docker container                                                                              |
|                       |  2. enter on container shell(if you run win-env.cmd you will auto enter on shell after container run) |
|                       |  3. write ninja on shell                                                                              |
+-----------------------+-------------------------------------------------------------------------------------------------------+
