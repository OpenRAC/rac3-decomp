/* PAL near miss (Codex wave 7): near miss: 183 words differ with the file's flags.
 * Study aid: it uses volatile, which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: 181 diff: build/codex/w356/func_0012B300.check2.log; retail 16-byte save spacing vs compiler 8-byte slots; two explicit delay loops at 0012B400/0012B488 and uncached IOP reply address shape remain; fixed flags only
 */
#include "common.h"
/* localdecomp:start func_0012B300 */
extern s32 D_0013F95C[], D_0013F958[], D_0013F924[];
extern s32 D_0013F948[], D_0013F94C[], D_0013F950[], D_0013F938[];
extern s32 D_15A3C0[];
extern u8 D_15A368[];
extern volatile s32 D_00140B00[], D_20140B00[];
extern char D_00151458[], D_00151478[];
extern s32 D_0013F944[];
s32 func_0012B300(s32 mode)
{
    extern s32 func_0012B138(s32);
    extern void func_00121FE8(s32);
    extern s32 func_00122630(void *, s32, s32);
    extern void func_00121760(const char *, ...);
    extern void func_00121F38(void *, s32);
    extern s32 func_00122810(void *, s32, s32, void *, s32, volatile void *, s32, s32, s32);
    extern void func_0012AD28(void);
    extern void func_0012AC40(void);
    extern void func_0012AE20(void);
    s32 result, status, a, b, count;
    volatile s32 *reply;
    if (func_0012B138(1)) return 0;
    func_00121FE8(0);
    D_0013F924[0] = 1;
    D_0013F95C[0]++;
    D_0013F948[0] = -1;
    D_0013F94C[0] = -1;
    D_0013F93C = -1;
    D_0013F954 = -1;
    D_0013F950[0] = -1;
    D_0013F938[0] = 0;
    D_0013F958[0] = -1;
    for (;;) {
        status = func_00122630(D_15A368, 0x80000592, 0);
        if (status < 0) {
            if (D_0013F910 > 0) func_00121760(D_00151458, status, D_0013F95C[0]);
            count = 0x100000; do { --count; } while (count != -1);
        } else if (*(s32 *)(D_15A368 + 0x24)) break;
        else { count = 0x100000; do { --count; } while (count != -1); }
    }
    D_15A3C0[0] = mode;
    D_0013F958[0] = 0;
    func_00121F38(D_15A3C0, 4);
    if (func_00122810(D_15A368, 0, 0, D_15A3C0, 4, D_00140B00, 16, 0, 0) < 0) {
        D_0013F924[0] = 0;
        return 0;
    }
    reply = D_20140B00;
    status = reply[3];
    a = reply[1];
    b = reply[2];
    result = 1;
    if (status == 255) { }
    else if (status == 254) D_0013F910 = 1;
    else if (a / 256 < 2 || b / 256 < 2) result = 2;
    D_0013F924[0] = 0;
    if (mode >= 0 && mode >= 2 && mode == 5) {
        if (D_0013F910 > 0) func_00121760(D_00151478);
        func_0012AD28();
        D_0013F928 = -1;
        D_0013F92C = -1;
        D_0013F920 = -1;
        D_0013F944[0] = 0;
    } else {
        func_0012AC40();
        func_0012AE20();
        D_0013F944[0] = 1;
    }
    return result;
}
/* localdecomp:end func_0012B300 */
