/* NTSC-U draft (Codex wave 4): C of func_L39_004F14C0, the NTSC-U twin of func_L39_004F16C0, with NTSC-U names and addresses.
 * near miss: 78 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_004F14C0").
 * Worker's note: sister build/codex/pool/X4/us_func_L39_004F14C0_rac4.c; best log build/codex/w184/func_L39_004F14C0-01.log; 78 diff: sister @ee29 code has 0x60 frame with 16-byte save spacing and reverse save order, assigned SN flags give 0x30 frame with 8-byte slots plus ...
 */
#include "common.h"
/* localdecomp:start func_L39_004F14C0 */
typedef struct Key_004F14C0 { s32 len; s32 pad4; s32 data; } Key_004F14C0;
typedef struct Item_004F14C0 { s32 pad0; s32 sub; Key_004F14C0 *key; s32 val; } Item_004F14C0;
typedef struct List_004F14C0 { s32 count; Item_004F14C0 **items; } List_004F14C0;
typedef struct Obj_004F14C0 { s32 pad0; List_004F14C0 *list; } Obj_004F14C0;





s32 func_L39_004F14C0(Obj_004F14C0 *a, Obj_004F14C0 *b) {
    extern s32 func_0011D2EC(s32, s32, s32);
    extern s32 func_L39_004E0C98(s32, s32);
    s32 i;
    s32 d;
    Item_004F14C0 *x;
    Item_004F14C0 *y;

    if (a->list->count != b->list->count) {
        return a->list->count - b->list->count;
    }
    for (i = a->list->count - 1; i >= 0; i--) {
        x = a->list->items[i];
        y = b->list->items[i];
        d = x->key->len - y->key->len;
        if (d != 0) {
            return d;
        }
        d = func_0011D2EC(x->key->data, y->key->data, x->key->len);
        if (d != 0) {
            return d;
        }
        d = x->val - y->val;
        if (d != 0) {
            return d;
        }
    }
    for (i = a->list->count - 1; i >= 0; i--) {
        x = a->list->items[i];
        y = b->list->items[i];
        d = func_L39_004E0C98(x->sub, y->sub);
        if (d != 0) {
            return d;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004F14C0 */
