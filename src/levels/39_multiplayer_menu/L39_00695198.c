#include "common.h"

/* localdecomp:start func_L39_00695198 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00695198(void *);

extern void func_L39_0067F168();
void func_L39_00695198(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00695198 */

/* localdecomp:start func_L39_006951C8 */
typedef struct V_006951C8 V_006951C8;
typedef struct { u8 pad[0x60]; V_006951C8 *vt; } O_006951C8;
struct V_006951C8 {
    u8 pad[0xC4];
    s32 (*text)(O_006951C8 *);
};
typedef struct { u8 pad[0x34]; u8 f34; } Q_006951C8;
typedef struct { u8 pad[0x38]; Q_006951C8 *f38; } G_006951C8;
typedef struct {
    u8 pad0[0x114];
    O_006951C8 *f114;
    u8 pad1[0x2AC - 0x118];
    u8 f2ac;
    u8 pad2[0x2B4 - 0x2AD];
    s32 f2b4;
} S_006951C8;
__asm__(".extern D_L39_0024D760, 16");
extern G_006951C8 *D_L39_0024D760;
__asm__(".extern D_L39_00247914, 16");
extern void *D_L39_00247914;
extern u8 D_L39_00247F60[];
extern s32 func_L39_00695328(S_006951C8 *);
extern void func_L39_00695368(u8 *);
extern s32 func_L39_0068AEF8(S_006951C8 *, s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_00120D28(s32, s32, s32);
extern void func_L39_00687450(void *, u8 *, u8 *, s32, s32, s32, s32);
extern void func_L39_006CF770(Q_006951C8 *);
extern void func_L39_006CF5A8(Q_006951C8 *, s32, u8 *);
extern void func_L39_006CF3E8(Q_006951C8 *, u8 *);

s32 func_L39_006951C8(S_006951C8 *p, s32 arg1)
{
    u8 buf[200];
    s32 n;
    s32 x;
    Q_006951C8 *q = D_L39_0024D760->f38;

    if (func_L39_00695328(p) != 0) {
        return 1;
    }
    func_L39_00695368((u8 *)p);
    if (func_L39_0068AEF8(p, arg1) != 0) {
        return 1;
    }
    if (q->f34 == 0 || p->f2ac != 0 || arg1 != 6) {
        return 0;
    }
    func_L39_00688340(4, 0, 0);
    func_00120D28((s32)buf, p->f114->vt->text(p->f114), 200);
    buf[199] = 0;
    x = p->f2b4;
    if (x == 0) {
        buf[0] = 0;
    }
    func_L39_00687450(D_L39_00247914, D_L39_00247F60, buf, 0, 200, 0, 0);
    n = p->f2b4;
    x = buf[0];
    if (x == 0) {
        func_L39_006CF770(q);
    } else if (n > 0) {
        func_L39_006CF5A8(q, n, buf);
    } else {
        func_L39_006CF3E8(q, buf);
    }
    x = 1;
    p->f2ac = x;
    return 1;
}
/* localdecomp:end func_L39_006951C8 */
