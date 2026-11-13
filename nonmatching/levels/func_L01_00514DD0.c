/* func_L01_00514DD0: 6 diff (about 10 compiles). Retail keeps the object pointer in $a0 (lw $a0,($a0)) and the index
   in $a1 (sll $a1,$a1,2), adds them into $v0, loads the entry into $v1 and moves it to $a0 for the call. This C puts the
   pointer in $v1, the shifted index in $v0 and the entry straight in $a0 (no move). */
typedef struct { u8 pad0[0x50]; void *tbl[0x23]; } T_00514DD0;
extern void func_L01_0051D3D8(void *p, s32 a);

s32 func_L01_00514DD0(T_00514DD0 **o, u32 i) {
    if (i < 0x23) {
        void *p = (*o)->tbl[i];
        if (p != 0) {
            func_L01_0051D3D8(p, 1);
            return 1;
        }
    }
    return 0;
}
