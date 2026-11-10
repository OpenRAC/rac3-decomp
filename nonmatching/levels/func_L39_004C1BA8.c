/* func_L39_004C1BA8: p2 match of the first 0x38 bytes (w8). Retail entry is 0x40 = this function + a separate 8-byte
   'jr ra; addiu v0,0x12c' (int f(void){return 300;}) at 004C1BE0; split the map entry, then this lands. */
extern int func_L39_004CBF60(unsigned char *);
extern int D_L39_00464A68[];

void func_L39_004C1BA8(void) {
    int v = func_L39_004CBF60(0);
    int *p = D_L39_00464A68;
    if (p[0x54 / 4] == 0) {
        p[0x54 / 4] = v + 0x10;
    }
}
