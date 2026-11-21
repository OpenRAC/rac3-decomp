/* functional: high. 14 words differ (scheduling/gp). Slot search by id (+0x64) over 13 slots; stores f24 always, f4 only when f68==0. */
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
void func_00393990(s32 id, s32 v) {
    s32 i;
    S_38ED78 *p = D_00331AE0;
    for (i = 0; i < 13; i++) {
        if (p[i].id == id) break;
    }
    if (i < 13) {
        S_38ED78 *q = &D_00331AE0[i];
        q->f24 = v;
        if (!q->f68) q->f4 = v;
    }
}
