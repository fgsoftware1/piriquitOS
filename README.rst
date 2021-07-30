+------------------------+---------------------------------+
|                        Setup                             |
+========================+=================================+
|      Windows(docker)   |docker-compose.yml               |
|                        |or                               |
|                        |win-env.cmd                      |
+------------------------+---------------------------------+
|                        |sudo bash linux-deps.sh(linux)   |
|         Linux          |and                              |
|                        |bash linux-env.sh(docker)        |
+------------------------+---------------------------------+

+------------------------+----------------------------------------------------------------------------------------------------+
|                                                     Build                                                                   |
+========================+====================================================================================================+
|      Windows(docker)   |run docker container                                                                                |
|                        |enter on container shell(if you run win-env.cmd you will auto enter on shell after container run)   |  
|                        |execute ninja on shell writing ninja                                                                |
+------------------------+----------------------------------------------------------------------------------------------------+
|                        |run sudo bash linux-deps.sh it will install dependencies and clone the repository                   |                                                           |
|         Linux          |enter on cloned repository                                                                          |
|                        |run ninja writing ninja                                                                             |
+------------------------+----------------------------------------------------------------------------------------------------+
