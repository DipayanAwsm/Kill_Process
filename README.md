============================================================================================
Author:Dipayan Das
Title:OSProject 2018 second Semester
Guide:Mandar Mitra
Be Happy!
contact:picku.pickudas@gmail.com
============================================================================================
SRC: This Project is to made to kill a processes and all spawned child processes.
     The only thing will need for this project is the processID that will be provided by user.
============================================================================================
This software is developped in ubuntu 18.04  environment and C lanuage this software is useful for linux environment 

gcc version is:gcc (Ubuntu 7.3.0-16ubuntu3) 7.3.0
so any gcc compiler withh version 7.3.0 or upper it will work.
============================================================================================
============================================================================================
Files Have Uses
1.OS.c
============================================================================================
=================================How to compile the Code====================================
1.gcc -g OS.c -o out
=================================How to Run the Code====================================
./out

=================================Software Walk Through====================================
1. you can run the program with providing only one argument, the argument will be process id.
eg:$ ./out 1234
//the up given process of the given processId will be terminated,the program will end
------------------------------------------------
2.You can Run the program with no argument.
and follw throgh the instruction in the program.
    i)There will be three options kill,Check process tree,and exit. 
    ii)In option 1, you have to provide the process id what you want to kill.
    iii)In option 2, You have to provide the process id whose tree you want to see, if you want to check entire process tree then please enter 0.
    iv)This will Exit the Program

 ****special Instruction:Please provide Integer values only dont try to have fun wile 
 killing the process.for example dont put process id as character, It may lead to System faliure,System lock down,Or some unknown Things.
 **** Its a prototype software so use it wisely. 
eg:$./out 
output:
$ ./out 

===============ProgramChoices==================
Enter 1 kill the Process
Enter 2 show All running the Process
Enter 0 Exit from the proccess
===============================================
2
Enter ProcessID OR '0' To see All the Process
14958
bash(14958)

===============ProgramChoices==================
Enter 1 kill the Process
Enter 2 show All running the Process
Enter 0 Exit from the proccess
===============================================
2
Enter ProcessID OR '0' To see All the Process
14198

===============ProgramChoices==================
Enter 1 kill the Process
Enter 2 show All running the Process
Enter 0 Exit from the proccess
===============================================
2   
Enter ProcessID OR '0' To see All the Process
15958

===============ProgramChoices==================
Enter 1 kill the Process
Enter 2 show All running the Process
Enter 0 Exit from the proccess
===============================================
2
Enter ProcessID OR '0' To see All the Process
14958
bash(14958)─┬─firefox(19008)─┬─Web Content(19178)─┬─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(191+
            │                │                    ├─{Web Content}(192+
            │                │                    ├─{Web Content}(192+
            │                │                    ├─{Web Content}(192+
            │                │                    └─{Web Content}(192+
            │                ├─{firefox}(19019)
            │                ├─{firefox}(19020)
            │                ├─{firefox}(19021)
            │                ├─{firefox}(19025)
            │                ├─{firefox}(19026)
            │                ├─{firefox}(19027)
            │                ├─{firefox}(19029)
            │                ├─{firefox}(19030)
            │                ├─{firefox}(19031)
            │                ├─{firefox}(19032)
            │                ├─{firefox}(19033)
            │                ├─{firefox}(19036)
            │                ├─{firefox}(19037)
            │                ├─{firefox}(19039)
            │                ├─{firefox}(19045)
            │                ├─{firefox}(19046)
            │                ├─{firefox}(19053)
            │                ├─{firefox}(19056)
            │                ├─{firefox}(19057)
            │                ├─{firefox}(19058)
            │                ├─{firefox}(19059)
            │                ├─{firefox}(19060)
            │                ├─{firefox}(19067)
            │                ├─{firefox}(19070)
            │                ├─{firefox}(19071)
            │                ├─{firefox}(19072)
            │                ├─{firefox}(19073)
            │                ├─{firefox}(19074)
            │                ├─{firefox}(19075)
            │                ├─{firefox}(19076)
            │                ├─{firefox}(19077)
            │                ├─{firefox}(19078)
            │                ├─{firefox}(19079)
            │                ├─{firefox}(19086)
            │                ├─{firefox}(19103)
            │                ├─{firefox}(19104)
            │                ├─{firefox}(19105)
            │                ├─{firefox}(19108)
            │                ├─{firefox}(19112)
            │                ├─{firefox}(19113)
            │                ├─{firefox}(19119)
            │                ├─{firefox}(19120)
            │                ├─{firefox}(19130)
            │                ├─{firefox}(19143)
            │                ├─{firefox}(19165)
            │                ├─{firefox}(19166)
            │                ├─{firefox}(19173)
            │                ├─{firefox}(19174)
            │                ├─{firefox}(19176)
            │                ├─{firefox}(19177)
            │                ├─{firefox}(19182)
            │                ├─{firefox}(19205)
            │                ├─{firefox}(19208)
            │                ├─{firefox}(19213)
            │                ├─{firefox}(19264)
            │                ├─{firefox}(19270)
            │                ├─{firefox}(19651)
            │                └─{firefox}(19652)
            └─gedit(18806)─┬─{gedit}(18808)
                           ├─{gedit}(18809)
                           └─{gedit}(18810)

===============ProgramChoices==================
Enter 1 kill the Process
Enter 2 show All running the Process
Enter 0 Exit from the proccess
===============================================
1
Enter Process ID:14958                        

===============ProgramChoices==================
Enter 1 kill the Process
Enter 2 show All running the Process
Enter 0 Exit from the proccess
===============================================
0
Happy Doing Worlk with You,Mangalam Bhabatu.




################################################
===============================================
This Provides list of child processes
 ps -e -o ppid= -o pid=

 /*This will provie rthe terminals process id*/
 echo $$
===============================================
################################################
