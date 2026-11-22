#include "common.h"

/* declared by functions of L39_0050D5B0.c, which this file was cut from */
extern s32 func_L39_0050DBB0(const void *src, void *dst);
extern s32 func_L39_0050DBC8(void *a0, void *a1, void *a2, void *a3);

/* localdecomp:start func_L39_0050DBB0 */
typedef struct {
    u8 *data;
    u32 remaining;
} Cursor_0050DBB0;
typedef struct {
    u8 prefix[12];
    Cursor_0050DBB0 cursor;
} Input_0050DBB0;

s32 func_L39_0050DBB0(const void *src, void *dst) {
    *(Cursor_0050DBB0 *)dst = ((const Input_0050DBB0 *)src)->cursor;
    return 0;
}
/* localdecomp:end func_L39_0050DBB0 */

/* localdecomp:start func_L39_0050DBC8 */
typedef struct S_0050DBC8 { u8 *p; s32 n; } S_0050DBC8;
extern s32 func_L39_0050CC00(void *, s32, s32, u8 *, s32);

s32 func_L39_0050DBC8(void *a0, void *a1, void *a2, void *a3)
{
    S_0050DBC8 *s = a3;

    if (s == 0 || s->p == 0)
        return 0;
    return func_L39_0050CC00(a0, (s32)a1, (s32)a2, s->p, s->n);
}
/* localdecomp:end func_L39_0050DBC8 */

/* localdecomp:start func_L39_0050DC08 */
typedef struct S_0050DC08 {
    s32 p;
    s32 n;
    s32 tag;
    s32 ip;
    s32 in;
} S_0050DC08;

s32 func_L39_0050DC08(S_0050DC08 *in, S_0050DC08 *out) {
    u8 *p = (u8 *)in->ip;
    u32 tag = *p;

    if (tag < 8) {
        if (tag != 0) {
            if ((u32)in->in < 2) {
                return 0x801;
            }
        }
        if (in->in == 1) {
            out->p = 0;
            out->n = 0;
            out->tag = 0;
        } else {
            out->p = (s32)(p + 1);
            out->n = in->in - 1;
            out->tag = *(u8 *)in->ip;
        }
        return 0;
    }
    return 0x801;
}
/* localdecomp:end func_L39_0050DC08 */
