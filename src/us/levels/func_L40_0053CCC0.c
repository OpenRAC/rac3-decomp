#include "common.h"

/* NTSC-U counterpart of func_L40_0053F570 (src/levels/shared/L40_0053F508.c): the same code, its globals at their NTSC-U addresses (the frame counter D_001A5F78) */
/* localdecomp:start func_L40_0053CCC0 */
extern s32 func_L40_0053CC58(s32 a0);
typedef struct {
    s32 value;
    u8 pad04[0x10];
    u8 *callback;
    s32 unk18;
    u8 *moby;
    s32 time;
    s32 unk24;
    s32 a;
    s32 b;
    u8 kind;
    u8 state;
    u8 pad32[6];
    s32 zero;
    s32 value2;
    s32 time2;
} Entry_0053CCC0;

typedef struct {
    s32 id;
    s32 x4;
    s32 x8;
    s32 xC;
} Param_0053CCC0;

extern s32 func_L40_0053CBE8(void);
extern s32 func_L39_00669B20(s32);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L39_0067CF88_0053CCC0(void);
/* the moby array base, read through $gp (an alias with the size hint) and with lui/lw */
extern u8 *D_L40_002485DC_0053CCC0;
__asm__(".extern D_L40_002485DC_0053CCC0, 4");
extern u8 *D_L40_002485DC;
__asm__(".extern D_L40_002485DC, 16");
extern u8 D_L40_002463D0[] __attribute__((section(".sdata")));
/* the file's D_L40_0033F460 (declared E_0053CC58[] in the PAL file) seen as an array of whole entries:
   gcc builds the address of a field of a real array element as (base + field) + index, which
   combine and the post-reload cse turn into retail's three base sums and register copies; a
   cast pointer gives one shared base instead */
extern Entry_0053CCC0 D_L40_0033F460_0053CCC0[];
extern Param_0053CCC0 D_L40_003401B0[];
extern s32 D_001A5F78[];

static __inline__ void init_0053CCC0(Entry_0053CCC0 *e) {
    e->callback = D_L40_002463D0;
}

u8 *func_L40_0053CCC0(s32 type, s32 value, s32 value2, s32 kind, u8 *obj) {
    s32 i;
    s32 j;

    i = func_L40_0053CBE8();
    if (i < 0) {
        return 0;
    }
    j = func_L39_00669B20(type);
    if (j < 0) {
        return 0;
    }
    if ((s32)obj == -1) {
        obj = func_003BCFB0(type, 0x400);
        if (obj == 0) {
            return 0;
        }
    } else {
        obj = (u8 *)((s32)obj << 8);
        func_L40_0053CC58((s32)(D_L40_002485DC_0053CCC0 + (s32)obj));
        obj = obj + (s32)D_L40_002485DC;
        obj[0x20] = 0;
    }
    init_0053CCC0(&D_L40_0033F460_0053CCC0[i]);
    D_L40_0033F460_0053CCC0[i].kind = kind;
    D_L40_0033F460_0053CCC0[i].moby = obj;
    D_L40_0033F460_0053CCC0[i].state = 1;
    D_L40_0033F460_0053CCC0[i].time = D_001A5F78[0];
    D_L40_0033F460_0053CCC0[i].value = value;
    D_L40_0033F460_0053CCC0[i].a = D_L40_003401B0[j].x4;
    D_L40_0033F460_0053CCC0[i].b = D_L40_003401B0[j].x8;
    D_L40_0033F460_0053CCC0[i].value2 = value2;
    D_L40_0033F460_0053CCC0[i].time2 = D_001A5F78[0];
    D_L40_0033F460_0053CCC0[i].zero = 0;
    *(Entry_0053CCC0 **)(obj + 0x90) = &D_L40_0033F460_0053CCC0[i];
    func_L39_0067CF88_0053CCC0();
    return obj;
}
/* localdecomp:end func_L40_0053CCC0 */
