#include "common.h"

/* NTSC-U counterpart of func_L07_003334A8 (src/levels/07_annihilation_nation/L07_00332098.c): 60 Hz delays 120/180/165 (PAL 100/150/137), NTSC-U level data addresses */
/* The PAL C with only the NTSC-U names and delays swapped $s2/$s3 (the %hi pseudos of D_001425C0 and the
 * item table): gcse numbers them by hash(name) mod S, S = 93 there; the u8 owned/level helpers add the
 * insns at gcse that give S = 95, retail's order (dead-set probe: +4..+7 matched). */
/* localdecomp:start func_L07_00332D68 */
typedef struct { s32 ids[4]; } Ids_00332D68;
typedef struct { u8 pad0; u8 level; u8 pad2[0x82]; u16 h84; u8 pad86[0x6A]; } Row_00332D68;
extern s32 D_L07_001DF458_00332D68;
extern u8 *D_L07_001DF41C_00332D68;
extern Ids_00332D68 D_L07_001DD148;
__asm__(".extern D_L07_001DD148, 16");
__asm__(".extern D_L07_001DF458_00332D68, 4");
__asm__(".extern D_L07_001DF41C_00332D68, 16");
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_L07_002C7280[];
extern u16 *D_L07_0021C020[];
extern s32 func_L07_003661D8(void);
extern s32 func_L07_00333068(s32 *);
/* the item row of id: owned (h84 != 0) and its level */
static inline u8 has_00332D68(s32 id) {
    return ((Row_00332D68 *)D_L07_002C7280)[D_001425C0[id]].h84 != 0;
}

static inline u8 level_00332D68(s32 id) {
    return ((Row_00332D68 *)D_L07_002C7280)[D_001425C0[id]].level;
}

s32 func_L07_00332D68(u8 *obj, s32 id) {
    u8 *vars=*(u8 **)(obj+0x68);
    s32 mode;
    s32 delay;
    Ids_00332D68 ids;
    if (!has_00332D68(id) && id!=0x87) return 0;
    if (D_001427F0[id]>0) {
        *(s16 *)(vars+0xB6)=0;
        return 0;
    }
    mode=0;
    ids=D_L07_001DD148;
    delay=120;
    switch(id) {
    case 0x7F: {
        s32 level=level_00332D68(0x7F);
        delay=180;
        if(level>=3) {
            ids.ids[0]=0x307;
            mode=2;
            if(level>=4) ids.ids[1]=0x1CB8;
        } else mode=1;
        break;
    }
    case 0x47: mode=1; delay=165; break;
    case 0x87: {
        u16 *q;
        u8 *e;
        if(obj[0x20]!=6 || func_L07_003661D8()) {
            *(s16 *)(vars+0xB6)=0;
            return 0;
        }
        
        for(q=D_L07_0021C020[*(s32 *)(vars+0x34)]; (*(s32 *)(vars+0x34)&255)!=255 && *(s32 *)(vars+0x34)<=D_L07_001DF458_00332D68 && q && ((s16)q[-1]>=0 || q==D_L07_0021C020[*(s32 *)(vars+0x34)]); q++) {
            e=D_L07_001DF41C_00332D68+((*q&0x7FFF)<<8);
            if(!e) break;
            if(e[0x20]!=1) {
                *(s16 *)(vars+0xB6)=0;
                return 0;
            }
        }
        mode=2;
        if(level_00332D68(0x87)>=4) ids.ids[0]=0x1893;
        else ids.ids[0]=0x1872;
        break;
    }
    case 0x4F: mode=2; ids.ids[0]=0x1867; break;
    case 0x5F: mode=2; ids.ids[0]=0x186B; break;
    case 0x8F: return 0;
    }
    switch(mode) {
    case 0: return 1;
    case 2: if(func_L07_00333068(ids.ids)) return 0;
    case 1:
        if(++*(s16 *)(vars+0xB6)>delay) return 1;
        break;
    }
    return 0;
}
/* localdecomp:end func_L07_00332D68 */
