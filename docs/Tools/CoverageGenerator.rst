==================
Coverage Generator
==================

The coverage generator tool outputs the basic block coverage of the specified modules.
There must be a file suffixed with ``.bblist`` on the module path. 
This file contains the list of basic blocks for the desired module. 

Here is an example of such a file (showing a few basic blocks from the rtl8139.sys driver shipped with Windows XP).

  ::
  
      0x00010300 0x0001031e RTFast_EnableInterrupt(x)
      0x0001031f 0x00010321 RTFast_EnableInterrupt(x)
      0x00010322 0x00010335 RTFast_DisableInterrupt(x)
      0x00010336 0x00010341 RTFast_DisableInterrupt(x)
      0x00010342 0x00010352 RTFast_Isr(x,x,x)
      0x00010353 0x00010360 RTFast_Isr(x,x,x)

Examples
~~~~~~~~

  ::

      $ /home/s2e/tools/Release/bin/coverage -trace=s2e-last/ExecutionTracer.dat -outputdir=s2e-last/ \
        -modpath=/home/s2e/experiments/rtl8139.sys/driver:/home/s2e/experiments/rtl8029.sys/driver


Required Plugins
~~~~~~~~~~~~~~~~

* ExecutionTracer
* TranslationBlockTracer

Optional Plugins
~~~~~~~~~~~~~~~~

* ModuleTracer (for debug information)

