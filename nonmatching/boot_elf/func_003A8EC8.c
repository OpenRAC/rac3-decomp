/* PAL near miss (Codex wave 6): near miss: 268 words differ with the file's flags.
 * Worker's note: 271 diff coreA-02.log. Context correction required: func_003AFC48 callback is s32(s32,s32), existing func_003A8BE8 is u32(s32,u32); direct named callback retained, no incompatible function cast. gp-vs-lui globals, loop allocation and scheduling also differ.
 */
#include "common.h"
/* localdecomp:start func_003A8EC8 */
extern s32 D_00227580_003A8EC8[];
extern s32 D_00142430_003A8EC8[];
extern s32 D_001DA058;
extern u8 D_00226000_003A8EC8[];
void func_003A8EC8(void)
{
    extern void func_00393028(void *);
    extern void func_003A1398(s32, s32);
    extern void func_00392E60(Object_0038E440 *, s32 *, s32 *);
    extern void func_003DA160(void);
    extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
    u8 message[16];
    s32 choice = 0, done = -1;
    s32 source, destination, output;
    s32 result = 0x140000, exit_loop = 0;
    s32 index, offset;
    u8 *state = (u8 *)&D_00225700;
    u8 *menu = (u8 *)D_00227400;
    u8 *table = D_00160C40_003A8C70;
    if (D_001DA034 == 0) {
        func_00393028(menu);
        func_003A1398(0, 0);
        return;
    }
    destination = D_00227580_003A8EC8[5];
    source = D_00227580_003A8EC8[3];
    output = destination + 0xF8000;
    func_003A96A8(1);
    D_001D4BB0 = D_001D4BB4;
    func_003916C8();
    func_003A9588();
    func_003A96A8(1);
    func_11F0A0(0);
    func_003A5830();
    func_003A2028();
    func_13CDF0_003A7A18(0);
    while (D_00142430_003A8EC8[0x15C/4] >= 3 || D_00142430_003A8EC8[0x164/4] >= 0)
        func_0039C7F0();
    do {
        if (D_001DA038 && *(s32 *)D_001DA038) {
            message[0] = 100;
            message[1] = D_001D52E0;
            message[2] = 0;
            func_13CDF0_003A7A18(0);
            func_13CD28(*(s32 *)D_001DA038 + *(s32 *)(table + 4), 16, output, message);
            func_13CDF0_003A7A18(0);
            *(s32 *)(state + 0x4C) = output;
        } else {
            *(s32 *)(state + 0x4C) = 0;
        }
        *(s32 *)(state + 0x34) = 0;
        func_003A8B90(source, D_001DA058 << 1, destination, 0xF8000);
        result = func_003AFC48(D_001DA030, D_001DA034, func_003A8BE8, D_001DA03C, D_001DA040);
        if (result == 1)
            menu[0x64] = 1;
        if (result && !(D_001D4D40 & 0x40)) {
            menu[0x64] = 1;
            func_00393028(menu);
        }
        if (*(s32 *)menu) {
            ++*(s32 *)menu;
            if (*(s32 *)menu + ((u8 *)&D_00143950_003A7328)[0xAD] >= 4)
                *(s32 *)menu = 1;
            if (*(s32 *)menu == 2) {
                D_001D4D40 = 0;
                if (((u8 *)&D_00143950_003A7328)[0xAD]) {
                    D_001DA040 = 0;
                    index = func_003A8B28(0x1D);
                } else {
                    D_001DA040 = 1;
                    index = func_003A8B28(0x1F);
                }
            } else if (*(s32 *)menu == 3) {
                D_001DA040 = 1;
                D_001D4D40 = 0;
                index = func_003A8B28(0x1E);
            } else {
                D_001DA040 = 0;
                D_001D4D40 = 1;
                index = func_003A8B28(0);
            }
            offset = (index << 4) | 8;
            D_001DA038 = (s32)(table + 8 + (index << 4));
            D_001DA030 = *(s32 *)(table + 8 + offset) + *(s32 *)(table + 4);
            D_001DA034 = *(s32 *)(table + 12 + offset);
        } else if (*(s32 *)(menu + 0x60) == 0) {
            exit_loop = 1;
        } else {
            func_00392E60((Object_0038E440 *)menu, &choice, &done);
            if (done == 0) {
                D_001DA040 = choice == 0x1F;
                index = func_003A8B28(choice);
                offset = (index << 4) | 8;
                D_001DA038 = (s32)(table + 8 + (index << 4));
                D_001DA030 = *(s32 *)(table + 8 + offset) + *(s32 *)(table + 4);
                D_001DA034 = *(s32 *)(table + 12 + offset);
            } else if (done == 1) {
                exit_loop = 1;
            }
        }
    } while (!exit_loop);
    func_13CDF0_003A7A18(0);
    func_12D4D8(D_13D208);
    func_12A9F0(0, 0);
    func_003DA160();
    *(long *)(D_00226000_003A8EC8 + 0x20) = 0;
    func_003A94C0();
    if (result == 0 && done == 1)
        func_003A12C0(2, 2, choice, 0, 0);
    else
        func_003A1398(0, 0);
}
/* localdecomp:end func_003A8EC8 */
