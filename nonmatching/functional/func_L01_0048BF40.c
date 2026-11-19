/* functional: high. check.py shows 1 differing instruction (loop counter initial register); behaviour identical to retail. */
typedef struct { s32 id; u8 flag; u8 pad[0xAB]; } Slot_00233DD8;
extern Slot_00233DD8 D_L01_00233DD8[];
extern s32 D_L01_001D8A10;
extern s32 D_L01_001D8A2C;

s32 func_L01_0048BF40(void) {
    s32 id = D_L01_001D8A10;
    s32 found = 0;
    s32 i;
    if (id >= 0) {
        for (i = found; i < 30; i++) {
            if (D_L01_00233DD8[i].id == id && D_L01_00233DD8[i].flag != 0) {
                D_L01_001D8A2C = i;
                found = 1;
                break;
            }
        }
    }
    D_L01_001D8A10 = -1;
    return found;
}
