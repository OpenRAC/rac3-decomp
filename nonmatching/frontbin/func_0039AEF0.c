/* US draft of func_0039AEF0 (rac3-uya-decomp func_00396100, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;

extern s32 D_001D4CE8[];
/* localdecomp:start func_0039AEF0 */
typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;

extern S_142430x D_142430;
extern s32 D_001D4CE8_g;

void func_0039AEF0(void) {
    S_142430x *p = &D_142430;
    D_001D4CE8_g = 4;
    p->f17C = 0;
    p->f10 = 0;
}
/* localdecomp:end func_0039AEF0 */
