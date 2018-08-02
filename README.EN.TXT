							F	A	Q  
							=========

1.What is this ?
================

* The Debugsim is debug sim on x86 or x64. 	We just do add
  portable 8086 Simulator.

  
  
2.What we do this ?
===================

* I would like to write a tools use debug on x86 or x64 
  cpu, To study for Dissemeber language. As we kown, the  
  debug just runnig on Dos os. It's too old, and using 
  it on vistual machine is not cheap.

  

3.How use it ?
==============
* It's compatible whit the debug on dos os.
  And i add some ISA for use.

  
  

4.How is the Debugsim arch ?
============================
* See the dir doc.



5.The design of debugsim.
=========================


								+------------------+
								|	 Debugsim      |
								+------------------+
										 |
								+------------------+		 +-----------------+
								| Command Transter |-------->|	ISA Simulator  |
								+------------------+		 +-----------------+
										 |									   |
			   +-----+--+---------+--+-------+--+--------+--+----------+	   |
			   | Mem |  |Register |	 |IO Port|  |Assember|  |Dissemeber|	   |
			   +-----+--+---------+--+-------+--+--------+--+----------+	   |
                  |          |           |                                     |
                  +<---------+<----------+<------------------------------------+
				  
				  
6.Devolper must know.
=====================
* We should use the old C89 standard, because we must keep the MSVC++ 6.0 must compiler it.
  We must make sure that this project can be compilered by C89 C compiler.
  
* How To build this project ?

  --make_vc.bat			For build on Windows using VC++ compiler. You must set the Envarment for compiler.
  --make_gcc.sh			For build on Linux and FreeBSD or Other Unix like System. It's lanuch by Bash and Compiler by Gnu C compiler(GCC).

