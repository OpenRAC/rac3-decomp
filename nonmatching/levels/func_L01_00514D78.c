/* func_L01_00514D78: 7 diff (about 10 compiles), the same shape as func_L01_00514DD0. Retail keeps the object pointer in $a0
   (lw $a0,($a0)) and the index in $a1 (sll $a1,$a1,2), adds them into $v0 (index first), loads the entry into $v1 and
   moves it to $a0 in the jal delay slot. This C puts the pointer in $v0, the shifted index in $v1 and loads the entry
   straight into $a0 (no move). Tried: index-first address sums, a K&R callee, an s32 entry, early returns. */
typedef struct { u8 pad0[0x50]; void *tbl[0x23]; } T_00514D78;
extern s32 func_L01_0051D400(void *p, s32 a);

s32 func_L01_00514D78(T_00514D78 **o, u32 i, u8 *out) {
    if (i < 0x23) {
        void *p = (*o)->tbl[i];
        if (p != 0) {
            *out = func_L01_0051D400(p, 1);
            return 1;
        }
    }
    return 0;
}
