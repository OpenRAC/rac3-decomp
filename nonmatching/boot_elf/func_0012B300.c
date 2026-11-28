/* Wave 13 (c44, 2026-11-28) replaces the earlier draft of this function (Codex wave 7 near miss). */
/* PAL near miss (wave 13c, worker c44): func_0012B300 (libcdvd init, 2.9-ee-991111 code).
 * Line: the whole one-function file 12B300.c on "@ee29 -O2 -G0" (neighbours 0x0012B138 / 0x0012B5E8);
 * 30 words differ there (182 with the file's SN line). Frame, loops, RPC calls, reply reads and the mode
 * switch match. D_0013F924 is volatile: the SIF command handler func_0012ADC8 (interrupt context) reads it;
 * without volatile 156 words differ (its %hi is CSE'd into a saved register; retail rematerialises it).
 * Left: the init block after func_00121FE8: retail loads D_0013F95C only after the D_0013F924 store and gives
 * %hi(D_0013F958) s4 / %hi(D_0013F95C) s5 (here the load is hoisted and s4/s5 swap). Only a volatile access to
 * D_0013F95C at that point orders it (diagnostic: (*(volatile s32 *)&D_0013F95C)++ gives 15 diff, not allowed);
 * declaring D_0013F95C volatile breaks the %hi sharing with the in-loop printf read (103 diff).
 */
/* localdecomp:start func_0012B300 */
/* libcdvd: init RPC bind, then the init call (mode 5 = exit); 2.9-ee-991111 */
typedef struct {
    u8 pad[0x24];
    s32 serve;
} Cd_12B300;

extern volatile s32 D_0013F924;
extern s32 D_0013F938;
extern s32 D_0013F944;
extern s32 D_0013F948;
extern s32 D_0013F94C;
extern s32 D_0013F950;
extern s32 D_0013F958;
extern s32 D_0013F95C;
extern Cd_12B300 D_15A368;
extern s32 D_15A3C0;
extern s32 D_00140B00[];
extern char D_00151458[];
extern char D_00151478[];
extern void func_00121F38(void *, s32);
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
extern void func_0012AD28(void);
extern void func_0012AC40(void);
extern s32 func_0012AE20(void);

s32 func_0012B300(s32 mode) {
    s32 r;
    s32 ret;
    s32 i;
    s32 status;
    s32 a;
    s32 b;
    s32 *rb;

    if (func_0012B138(1) != 0) {
        return 0;
    }
    func_00121FE8(0);
    D_0013F95C++;
    D_0013F924 = 1;
    D_0013F948 = -1;
    D_0013F94C = -1;
    D_0013F93C = -1;
    D_0013F954 = -1;
    D_0013F950 = -1;
    D_0013F938 = 0;
    D_0013F958 = -1;
    while (1) {
        r = func_00122630(&D_15A368, 0x80000592, 0);
        if (r < 0) {
            if (D_0013F910 > 0) {
                func_00121760_0012B1A8(D_00151458, r, D_0013F95C);
            }
            i = 0x100000;
            while (--i != -1) {
            }
            continue;
        }
        if (D_15A368.serve != 0) {
            rb = D_00140B00;
            D_15A3C0 = mode;
            D_0013F958 = 0;
            func_00121F38(&D_15A3C0, 4);
            if (func_00122810(&D_15A368, 0, 0, &D_15A3C0, 4, rb, 0x10, 0, 0) < 0) {
                D_0013F924 = 0;
                return 0;
            }
            break;
        }
        i = 0x100000;
        while (--i != -1) {
        }
    }
    a = *(s32 *)((u32)&rb[1] | 0x20000000);
    b = *(s32 *)((u32)&rb[2] | 0x20000000);
    status = *(s32 *)((u32)&rb[3] | 0x20000000);
    ret = 1;
    if (status != 0xFF) {
        if (status == 0xFE) {
            D_0013F910 = 1;
        } else if (a / 256 < 2 || b / 256 < 2) {
            ret = 2;
        }
    }
    D_0013F924 = 0;
    switch (mode) {
    case 5:
        if (D_0013F910 > 0) {
            func_00121760_0012B1A8(D_00151478);
        }
        func_0012AD28();
        D_0013F928 = -1;
        D_0013F92C = -1;
        D_0013F920 = -1;
        D_0013F944 = 0;
        break;
    case 0:
    case 1:
    default:
        func_0012AC40();
        func_0012AE20();
        D_0013F944 = 1;
        break;
    }
    return ret;
}
/* localdecomp:end func_0012B300 */
