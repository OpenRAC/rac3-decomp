/* PAL near miss (Codex wave 8): near miss: 108 words differ with the file's flags.
 * Worker's note: 108 diff; w446/func_L01_004C44D8.a2.log; context blocker: owner func_0011B2E8(char*,char*,char*,s32) requires fourth argument but retail prepares only three; draft supplies 0 to honor owner signature, adding move a3,zero; Claude must review variadic ...
 */
#include "common.h"
/* localdecomp:start func_L01_004C44D8 */
typedef struct { s32 id, price; u8 gap8[12]; char *label; u8 gap18[8]; u8 flag; u8 gap21[3]; } Entry_004C44D8;
typedef struct { u8 gap0[4]; s32 timer; u8 gap8[0x78]; s32 selected; u8 gap84[0xBC]; Entry_004C44D8 entries[1]; } Vendor_004C44D8;
extern G_004BF8A0 D_L01_002446C0;
extern char D_L01_0024DE50[];
extern char D_L01_001DAE40[];
extern s32 D_L01_001E0F7C;
extern s32 D_L01_001E0F80;
extern u8 D_L01_001E0FF0[8];
extern u8 D_L01_001E1038[8];
extern s32 D_00142660[];
extern u8 D_L01_002F2CD8[];
void func_L01_004C44D8(void) {
    extern void func_0011B2E8(char *, char *, char *, s32);
    extern void func_L01_004C42D0(s32);
    extern void func_L01_004BEC88(char *, s32);
    extern void func_L01_00516EC8(s32, f32 *, f32 *, f32 *, f32 *);
    extern void func_L01_00516470(s32, f32, f32);
    extern void func_L01_00516D60(s32, s32);
    extern VObj_4BEB00 *func_003B42F8(s32);
    extern void func_L01_004C0FD8(u8 *, s32, u32);
    extern void func_L01_00517F50(s32, s32, s32);
    f32 discard;
    f32 x;
    s32 price;
    s32 enabled;
    s32 enough;
    u32 color;
    s32 on;
    /* The owner declares four fixed arguments; retail sets only three here. */
    func_0011B2E8(D_L01_0024DE50, D_L01_001DAE40, ((Vendor_004C44D8 *)&D_L01_002446C0)->entries[((Vendor_004C44D8 *)&D_L01_002446C0)->selected].label, 0);
    if (((Vendor_004C44D8 *)&D_L01_002446C0)->timer < 15) {
        D_L01_001E0F7C = ((Vendor_004C44D8 *)&D_L01_002446C0)->timer;
        func_L01_004C42D0(0);
    } else D_L01_001E0F80 = 0;
    price = ((Vendor_004C44D8 *)&D_L01_002446C0)->entries[((Vendor_004C44D8 *)&D_L01_002446C0)->selected].price;
    func_L01_004BEC88((char *)D_L01_001E0FF0, price);
    func_L01_00516EC8(0x48000C, &discard, &discard, &x, &discard);
    func_L01_00516470(0x48000F, x + 0.015f, 0.645f);
    func_L01_00516EC8(0x48000F, &discard, &discard, &x, &discard);
    func_L01_00516470(0x48000D, x + 0.015f, 0.645f);
    enabled = ((Vendor_004C44D8 *)&D_L01_002446C0)->entries[((Vendor_004C44D8 *)&D_L01_002446C0)->selected].flag ^ 1;
    func_L01_00516D60(0x48000F, enabled);
    func_L01_00516D60(0x48000C, enabled);
    func_L01_00516D60(0x48000D, enabled);
    func_L01_00516D60(0x480017, enabled ^ 1);
    if (func_003B42F8(0)->p0 == 2 && func_003B42F8(1)->p0 == 2) {
        func_L01_00516D60(0x480019, 1);
        func_L01_00516D60(0x48001A, 1);
    } else {
        func_L01_00516D60(0x480019, 0);
        func_L01_00516D60(0x48001A, 0);
    }
    func_L01_004BEC88((char *)D_L01_001E1038, D_00142660[0]);
    enough = price < D_00142660[0];
    color = 0x80707070;
    if (enough) color = 0x8066CCFF;
    func_L01_004C0FD8(D_L01_002F2CD8, 0x48000D, color);
    func_L01_004C0FD8(D_L01_002F2CD8, 0x48000F, color);
    func_L01_00517F50(0x48000E, 0xEA97, ((Vendor_004C44D8 *)&D_L01_002446C0)->entries[((Vendor_004C44D8 *)&D_L01_002446C0)->selected].id);
    on = enough && enabled;
    func_L01_00516D60(0x480014, on);
}
/* localdecomp:end func_L01_004C44D8 */
