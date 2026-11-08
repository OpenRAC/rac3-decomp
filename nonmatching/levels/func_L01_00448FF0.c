/* Ported from rac4-decomp's func_00476660 (a twin of this function's code), names renamed from retail's
   relocations; 1 instruction(s) still differ under this file's flags. */
typedef struct { u8 pad[0x10]; s32 v; } Info;
typedef struct { u8 pad[0x34]; u16 flags; u8 pad36[0xAC - 0x36]; Info *info; } Obj;

s32 func_L01_00448FF0(Obj *o) {
    if (o == 0) {
        return 0;
    }
    if (o->flags & 0x20) {
        return o->info->v;
    }
    return 0;
}
