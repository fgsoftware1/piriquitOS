=======================   ======================================================================================================
     Windows(docker)        1. run docker container            
                            2. enter on container shell(if you run win-env.cmd you will auto enter on shell after container run)   
                            2. write ninja on shell                                                                                                                                                                    |
---------------------------------------------------------------------------------------------------------------------------------
      Linux(docker)         1. run docker container                                                                              
                            2. enter on container shell(if you run win-env.cmd you will auto enter on shell after container run) 
                            3. write ninja on shell                                                                              
=======================   =======================================================================================================

=====  =====  ======
   Inputs     Output
--------------------
  A      B    A or B
=====  =====  ======
False  False  False
True   False  True
False  True   True
True   True   True
=====  =====  ======
