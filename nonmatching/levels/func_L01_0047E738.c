/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0047AED8, the NTSC-U twin of func_L01_0047E738, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 2 words differ with its file's flags.
 */
#include "common.h"
/* localdecomp:start func_L01_0047AED8 */
extern void func_L01_0047AE20(void),func_L01_00475040(void),func_L01_00475078(int),func_0039EE68(void),func_L01_0047A240(void);
typedef struct { u8 pad[0x1a0]; int active; } State47;
extern State47 *D_001D52FC[];
extern int D_001D8250_sda;
extern u8 D_001D672E_sda;
extern u32 D_001D4CEC;
__asm__(".extern D_001D8250_sda, 4");
void func_L01_0047AED8(void) {
 func_L01_0047AE20();func_L01_00475040();func_L01_00475078(0);func_0039EE68();
 { int n=D_001D52FC[0]->active; if(n) { n=1800; D_001D8250_sda=n; } }
 D_001D8250_sda--;
 if(D_001D8250_sda<=0){D_001D8250_sda=0;D_001D672E_sda=1;}else D_001D672E_sda=0;
 if(D_001D4CEC&1)func_L01_0047A240();
}
/* localdecomp:end func_L01_0047AED8 */
