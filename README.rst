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
|      Windows(docker)   |1. run docker container                                                                             |
|                        |2. enter on container shell(if you run win-env.cmd you will auto enter on shell after container run)|  
|                        |3. execute ninja on shell writing ninja                                                             |
+------------------------+----------------------------------------------------------------------------------------------------+
|                        |1. run sudo bash linux-deps.sh it will install dependencies and clone the repository                |                                                           |
|         Linux          |2. enter on cloned repository                                                                       |
|                        |3. run ninja writing ninja                                                                          |
+------------------------+----------------------------------------------------------------------------------------------------+
