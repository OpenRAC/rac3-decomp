/* functional: high. No draft; written from PAL asm, compiles, 65 diff; seen[] bytes memset by func_0011D534 and set from each player's index at +0x2558; both exit paths and the loop break re-read */
/* localdecomp:start func_L40_00434AB8 */
typedef struct { s32 a, valid; s16 item; u8 kind, pad; } E_434AB8;
typedef struct {
    s32 pad0, stamp, last, player;
    s32 active, since;
    u8 pad18[0x18]; s32 values[8]; u8 flags[8]; E_434AB8 entries[8];
} P_434AB8;
extern s32 D_001A5CD0[];
extern u8 *D_L40_00249330[];
extern void *func_0011D534(void *, s32, s32);
extern void func_L40_004343F0(void *);
extern s32 func_L40_004341E8(void *);
extern void func_L40_00434398(void *, s32, s32);

void func_L40_00434AB8(u8 *m) {
    P_434AB8 *p = *(P_434AB8 **)(m + 0x68);
    s32 idx = D_001A5CD0[2];
    s32 i;
    s32 key;
    s32 ok;
    s32 allEqual;
    s32 cleared;
    u8 seen[8];
    u8 **tbl;
    u8 *pl;
    s32 *ref;

    if (p->active != 0) {
        key = 0;
        ok = 1;
        allEqual = 1;
        cleared = 0;
        if (p->entries[idx].valid == 0) {
            key = p->entries[idx].a;
            func_0011D534(seen, 0, 8);
            tbl = D_L40_00249330;
            for (i = 7; i >= 0; i--, tbl++) {
                pl = *tbl;
                if (pl != 0) {
                    ref = *(s32 **)(pl + 0x2558);
                    if (ref != 0) {
                        seen[*ref] = 1;
                    }
                }
            }
        } else {
            ok = 0;
        }
        if (ok) {
            for (i = 0; i < 8; i++) {
                if (seen[i] != 0) {
                    if (p->flags[i] == 0) {
                        ok = 0;
                        break;
                    }
                    if (p->values[i] != key) {
                        allEqual = 0;
                    }
                }
            }
            if (ok == 0) {
                if (p->since > 0 && p->since + 30000 < D_001A5CD0[0x128 / 4]) {
                    func_L40_004343F0(m);
                    cleared = 1;
                }
            } else {
                cleared = 1;
                if (!allEqual) {
                    func_L40_004343F0(m);
                }
            }
        }
        if (cleared) {
            p->active = 0;
            p->since = 0;
            func_0011D534(&p->entries[idx], 0, 12);
        }
    }
    for (i = 0; i < 8; i++) {
        if (p->entries[i].valid != 0) {
            if (func_L40_004341E8(&p->entries[i])) {
                func_L40_00434398(m, i & 0xFF, p->entries[i].a);
            }
        }
    }
}
/* localdecomp:end func_L40_00434AB8 */
