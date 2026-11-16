/* P06 wave 3 reconstruction from PAL retail, informed by the repository's
 * table-walk family (func_L01_0049DE10 / func_L02_00474518).
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division.
 * Stock check.py: 28 differing words, principally the PRE i+1 temporary,
 * saved-register reuse, and resulting suffix shift. Three valid control-flow
 * wordings gave the same residual. The earlier one-word diagnostic omitted
 * the default case's update and is NOT a valid near-match.
 * INCLUDE_ASM remains in the owner.
 */
#include "common.h"
typedef struct {
 s32 key,f4,f8;
 union { u32 flag; u32 *list; } value;
 s32 kind; u8 active; u8 pad[3];
} Entry_49BB68;
extern Entry_49BB68 D_L07_002EE2B8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 func_L01_0041A4F0(void);
void func_L07_0049BB68(void) {
 s32 i=0,j,n;
 while(D_L07_002EE2B8[i].key) {
  switch(D_L07_002EE2B8[i].kind) {
  case 0:
   D_L07_002EE2B8[i].active=((D_00142BA0[D_L07_002EE2B8[i].value.flag>>2]&(1<<(D_L07_002EE2B8[i].value.flag&31))) || func_L01_0041A4F0())?1:0;
   n=i+1;
   break;
  case 1: {
   D_L07_002EE2B8[i].active=0;
   n=i+1;
   for(j=0;D_L07_002EE2B8[i].value.list[j];j++) {
    u8 active=0;
    if(D_L07_002EE2B8[i].active || (D_00142BA0[D_L07_002EE2B8[i].value.list[j]>>2]&(1<<(D_L07_002EE2B8[i].value.list[j]&31))) || func_L01_0041A4F0()) active=1;
    D_L07_002EE2B8[i].active=active;
   }
   break;
  }
  case 2:
   D_L07_002EE2B8[i].active=((D_00142BA0[D_L07_002EE2B8[i].value.flag>>2]&(1<<(D_L07_002EE2B8[i].value.flag&31))) || func_L01_0041A4F0())?1:0;
   n=i+1;
   break;
  default: goto ordinary;
  case 3: case 4:
ordinary:
   D_L07_002EE2B8[i].active=(D_00142693[0] || func_L01_0041A4F0())?1:0;
   n=i+1;
   break;
  }
  i=n;
 }
}
