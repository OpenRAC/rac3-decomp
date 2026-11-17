#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* localdecomp:start func_003B6848 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B3228(void *); // Ensure this prototype matches exactly
extern void func_0039BD08(void (*)(), s32, void (*)());
extern void func_003B6638();
extern void func_003B6510();

void func_003B6848(void) {
    func_003B3228((void *)(s32)D_001D8A9C);
    
    // Explicit sequence point
    *(volatile s32 *)&D_001D8A40_g = 1; 
    
    func_0039BD08(func_003B6638, D_001D8AB4, func_003B6510);
}
/* localdecomp:end func_003B6848 */

/* localdecomp:start func_003B6888 */
extern void func_0039BE70(void);
extern s32 D_001D8A40_g;
void func_003B6888(void) {
    func_0039BE70();
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6888 */

/* localdecomp:start func_003B68B0 */
extern s32 func_0039BC70(s32, void *);
extern void func_003B6578();
extern s32 D_001D8A40_g;
s32 func_003B68B0(void) {
    s32 r = func_0039BC70(0, func_003B6578);
    D_001D8A40_g = 1;
    return r;
}
/* localdecomp:end func_003B68B0 */

/* localdecomp:start func_003B68E0 */
extern s32 func_0039BC70(s32, void *);
extern void func_003B6578();
extern s32 D_001D8A40_g;
s32 func_003B68E0(void) {
    s32 r = func_0039BC70(0, func_003B6578);
    D_001D8A40_g = 1;
    return r;
}
/* localdecomp:end func_003B68E0 */

extern unsigned char D_001D5BDC;
extern int D_001D8AB4;
extern int D_001D8A40_g;
extern void func_0039BDC0(int, int, int);
extern void func_003B66A0(void);
extern void func_003B66F0(void);
extern void func_003B67A8(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B6910);

/* localdecomp:start func_003B6970 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B3228(void *);
extern void func_0039BD08();
extern void func_003B6588();
void func_003B6970(void) {
    func_003B3228((void *)D_001D8A9C);
    func_0039BD08(func_003B6588, D_001D8AB4, 0);
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6970 */

/* localdecomp:start func_003B69B0 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B3228(void *);
extern void func_003B8A38(s32);
extern void func_0039BD08();
extern void func_003B6670();
extern void func_003B6548();
void func_003B69B0(void) {
    func_003B3228((void *)D_001D8A9C);
    func_003B8A38(D_001D8AB4);
    func_0039BD08(func_003B6670, D_001D8AB4, func_003B6548);
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B69B0 */
