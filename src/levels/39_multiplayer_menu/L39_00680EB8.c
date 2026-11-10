#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
extern void *func_L39_0067EE40(void *, void *);
extern void func_L39_0067EEC8(u8 *, s32);
s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00680EB8 */
void func_L39_00680EB8(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x147C) = 1;
}
/* localdecomp:end func_L39_00680EB8 */

/* localdecomp:start func_L39_00680EC8 */
s32 func_L39_00680EC8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x1468));
}
/* localdecomp:end func_L39_00680EC8 */

/* localdecomp:start func_L39_00680ED0 */
void *func_L39_00680ED0(void *arg0) {
    return arg0 + (((*(s32 *)((u8 *)arg0 + 0x1468)) * 0x50) + 0x68);
}
/* localdecomp:end func_L39_00680ED0 */

/* localdecomp:start func_L39_00680EE8 */
s32 func_L39_00680EE8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x1468)) != *(s32 *)((u8 *)arg0 + 0x146C);
}
/* localdecomp:end func_L39_00680EE8 */

/* localdecomp:start func_L39_00680F00 */
s32 func_L39_00680F00(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00680F00 */

/* localdecomp:start func_L39_00680F08 */
typedef struct {
    u8 pad[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    u8 f6C;
    s32 f70;
    s32 f74;
    u8 f78;
    s32 f7C;
    s32 f80;
} S_00680F08;
typedef struct {
    u8 pad[0x48];
    u8 f48;
    s32 f4C;
} S_00680F08_b;
extern u8 D_L39_0047B990[];
void *func_L39_0067EE40(void *, void *);

void *func_L39_00680F08(u8 *a0, u8 *a1) {
    S_00680F08 *arg0 = (S_00680F08 *)a0;
    S_00680F08_b *arg1 = (S_00680F08_b *)a1;
    func_L39_0067EE40(a0, a1);
    arg0->f64 = -1;
    arg0->f60 = D_L39_0047B990;
    arg0->f68 = -1;
    arg0->f7C = arg1->f4C;
    arg0->f70 = -1;
    arg0->f6C = arg1->f48;
    arg0->f80 = 0x80808080;
    arg0->f74 = 0;
    arg0->f78 = 0;
    return a0;
}
/* localdecomp:end func_L39_00680F08 */

/* localdecomp:start func_L39_00680F80 */
extern u8 D_L39_0047B990[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00680F80(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047B990;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00680F80 */

/* localdecomp:start func_L39_00680FA8 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00680FA8(void *arg0, s32 arg1, s32 arg2) {
    if (*(s32 *)((u8 *)arg0 + 0x64) != -1) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x68) != -1) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x68), arg1, arg2);
    }
    return 1;
}
/* localdecomp:end func_L39_00680FA8 */
