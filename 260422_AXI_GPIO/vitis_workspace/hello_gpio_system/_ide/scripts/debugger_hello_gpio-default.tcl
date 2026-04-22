# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: D:\workplace\AXI\260422_AXI_GPIO\vitis_workspace\hello_gpio_system\_ide\scripts\debugger_hello_gpio-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source D:\workplace\AXI\260422_AXI_GPIO\vitis_workspace\hello_gpio_system\_ide\scripts\debugger_hello_gpio-default.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Basys3 210183BB79E1A" && level==0 && jtag_device_ctx=="jsn-Basys3-210183BB79E1A-0362d093-0"}
fpga -file D:/workplace/AXI/260422_AXI_GPIO/vitis_workspace/hello_gpio/_ide/bitstream/design_1_wrapper.bit
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
loadhw -hw D:/workplace/AXI/260422_AXI_GPIO/vitis_workspace/design_1_wrapper/export/design_1_wrapper/hw/design_1_wrapper.xsa -regs
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
rst -system
after 3000
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
dow D:/workplace/AXI/260422_AXI_GPIO/vitis_workspace/hello_gpio/Release/hello_gpio.elf
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
con
