#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003AEB48(void *, s32);
extern void func_003AEC40(u8 *, s32, f32);
extern void func_003AAF00(void *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3AD328.c's earlier functions */
typedef struct {
    char pad_0[0x18];   
    f32 float_field;    
    char pad_1C[0xC];   
    char byte_flag;     
} InitContext;
extern void func_003AD500(InitContext* ctx);
extern void func_003AD590(u8 *p, s32 a);
extern u8 *func_003AD608(u8 *p);

/* localdecomp:start func_003AEB48 */

void func_003AEB48(void *arg0, s32 arg1) {
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_s5;

    (*(s32 *)((u8 *)(arg0) + 0xB38)) = arg1;
    if ((*(s32 *)((u8 *)(arg0) + 0xB3C)) != 0) {
        (*(s32 *)((u8 *)(arg0) + 0xB3C)) = 0;
        temp_s4 = arg0 + 0x7E8;
        func_003AAF00(arg0 + 0x628, 0);
        temp_s5 = arg0 + 0x870;
        func_003AD590(temp_s4, 1);
        temp_s3 = arg0 + 0x8F8;
        func_003AD590(temp_s5, 1);
        temp_s2 = arg0 + 0x980;
        func_003AD590(temp_s3, 1);
        temp_s1 = arg0 + 0xA08;
        func_003AD590(temp_s2, 1);
        temp_s0 = arg0 + 0xA90;
        func_003AD590(temp_s1, 1);
        func_003AD590(temp_s0, 1);
        func_003AD500(temp_s4);
        func_003AD500(temp_s5);
        func_003AD500(temp_s3);
        func_003AD500(temp_s2);
        func_003AD500(temp_s1);
        func_003AD500(temp_s0);
    }
}
/* localdecomp:end func_003AEB48 */

/* PAL candidate for func_003AEC40 (US draft func_003A9698). The US decompilation
   called the PAL function func_003825F8 as "func_0037E368"; PAL retail calls
   func_003825F8 at 0x3825F8. */


/* localdecomp:start func_003AEC40 */
typedef struct { u8 p0[0x1C4]; u32 f1C4; } S_3A9698;
extern S_3A9698 *D_001D52FC[];
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
extern s32 *func_003AAEB8();
extern f32 *func_003AB390();
extern void func_003AAF00();
void func_003AEC40(u8 *base, s32 b, f32 f) {
    s32 *r;
    f32 *q;
    u8 *p;
    if ((D_001D52FC[0]->f1C4 & 0xF000) != 0) {
        func_003825F8(0, 0, 1, 0, 1, 0);
    }
    p = base + 0x628;
    r = func_003AAEB8(p);
    *r = func_003825F8(0x331465B7, 0x706EC8FF, 0x14, 0, 0, 0);
    q = func_003AB390(p);
    *q = f;
    func_003AAF00(p, b);
}
/* localdecomp:end func_003AEC40 */

LINKER_REMNANT("asm/remnants", func_003AED00);

/* localdecomp:start func_003AED10 */
u8 *func_003AED10(u8 *p) {
    u8 *q; u8 *base; s32 i, j, k;
    base = p;
    for (j = 3; j != -1; j--) {
        q = base;
        for (k = 25; k != -1; k--) { func_003AB468(q); q += 0x3C; }
        base += 0x618;
    }
    func_003AB468(p + 0x1860);
    q = p + 0x18A0;
    for (i = 3; i != -1; i--) { func_003AD608(q); q += 0xB50; }
    func_003AB738(p + 0x45E0);
    q = p + 0x4610;
    for (i = 3; i != -1; i--) { func_003ABF70(q); q += 0x230; }
    func_003ABF70(p + 0x4ED0);
    return p;
}
/* localdecomp:end func_003AED10 */
