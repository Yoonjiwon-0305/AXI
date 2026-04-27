-makelib ies_lib/xpm -sv \
  "C:/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "C:/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib ies_lib/xpm \
  "C:/Xilinx/Vivado/2020.2/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../260422_AXI_GPIO.gen/sources_1/ip/GPIO_0/hdl/GPIO_v1_0_S00_AXI.v" \
  "../../../../260422_AXI_GPIO.gen/sources_1/ip/GPIO_0/hdl/GPIO_v1_0.v" \
  "../../../../260422_AXI_GPIO.gen/sources_1/ip/GPIO_0/sim/GPIO_0.v" \
-endlib
-makelib ies_lib/xil_defaultlib \
  glbl.v
-endlib

