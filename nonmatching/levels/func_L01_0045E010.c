/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_0045AD08, the NTSC-U twin of func_L01_0045E010, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_0045A6F0.c's current line.
 * Worker's note: 35 diff; documented assembler literal mismatch: permitted flags emit two lit4 loads for 0x3b64c389 and 0x3e98825b instead of retail inline lui ori mtc1; no forbidden flags tried; best log func_L01_0045AD08.02.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_0045AD08 */
extern float func_L01_0044E480(void*,void*,int);
extern void func_L01_00445758(void*,void*,int,float,float,float,float);
extern void func_00388BD0(void*,void*);
extern void func_00388EB8(void*,void*,void*);
float func_L01_0045AD08(char *m,char *state,vu0_v4 *input,int mode) {
 vu0_v4 v; float matrix[12] __attribute__((aligned(16)));int zero;float angle;
 v=*input;
 angle=func_L01_0044E480(m,&v,mode);
 zero=0;
 func_L01_00445758(&zero,state+0xb4,0,angle,0.0034906587097793818f,0.0034906587097793818f,0.2978695333003998f);
 qzero(&v);
 v.z=*(float*)(state+0xb4);
 func_00388BD0(matrix,&v);
 func_00388EB8(m+0xc0,m+0xc0,matrix);
 return fabs_asm(angle)-fabs_asm(*(float*)(state+0xb4));
}
/* localdecomp:end func_L01_0045AD08 */
