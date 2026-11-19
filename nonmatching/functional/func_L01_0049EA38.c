/* functional: high. Jump table (kinds 0..4: 0,2 single id; 1 list; 3 byte; 4 id chain) from level-02 copy; the compare tree is a binary search in retail, written as a switch with the 19 ids decoded one by one; raw addresses named as D_0014xxxx/D_001D55xx core data; bitmap word index id>>2 (not id>>5) copied exactly as retail does */
extern E_49E5B8 D_L01_002ECBA8[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern u8 D_0014271C[];
extern u8 D_001427A2[];
extern u8 D_001427AC[];
extern u8 D_001427AD[];
extern u8 D_001427AE[];
extern u8 D_001427AF[];
extern u8 D_001427B0[];
extern u8 D_001427B1[];
extern u32 D_00142C0C[];
extern u32 D_00142C4C[];
extern u32 D_00142C5C[];
extern u8 D_001D5576[];
extern u8 D_001D5577[];
extern u8 D_001D557A[];
extern u8 D_001D5587[];
extern u8 D_001D5588[];
extern u8 D_001D558B[];
extern u8 D_001D558C[];

void func_L01_0049EA38(void) {
    s32 i = 0;
    s32 j;
    s32 id;
    s32 arg;
    s32 *list;
    E_49E5B8 *row;

    if (D_L01_002ECBA8[0].x0 == 0) return;
    do {
        row = &D_L01_002ECBA8[i];
        switch (row->x10) {
        case 1:
            row->x14 = 1;
            list = (s32 *)row->xC;
            if (list[0] != 0) {
                j = 0;
                do {
                    if (row->x14 != 0) {
                        id = ((s32 *)row->xC)[j];
                        row->x14 = (D_00142BA0[id >> 2] & (1 << (id & 0x1F))) != 0;
                    } else {
                        row->x14 = 0;
                    }
                    j++;
                } while (((s32 *)row->xC)[j] != 0);
            }
            i++;
            break;
        case 0:
        case 2:
            id = row->xC;
            row->x14 = (D_00142BA0[id >> 2] & (1 << (id & 0x1F))) != 0;
            i++;
            break;
        case 3:
            row->x14 = D_00142693[0] != 0;
            i++;
            break;
        default:
            switch (row->x0) {
            case 0x15E9: arg = D_001D5587[0] != 0; break;
            case 0xE47: arg = D_001D5577[0] != 0; break;
            case 0xBC5: arg = D_001427B1[0] != 0; break;
            case 0x52F: arg = D_001D5588[0] != 0; break;
            case 0xD3D: arg = D_001427B0[0] != 0; break;
            case 0xE46: arg = D_001427AD[0] != 0; break;
            case 0xE49: arg = D_001427AE[0] != 0; break;
            case 0xE48: arg = D_001D558C[0] != 0; break;
            case 0xE4B: arg = D_001427AF[0] != 0; break;
            case 0x13A3: arg = D_001427A2[0] != 0; break;
            case 0x15EE: arg = (D_00142C0C[0] & 0x1000) != 0; break;
            case 0x15EB: arg = D_001D558B[0] != 0; break;
            case 0x15EA: arg = D_001D557A[0] != 0; break;
            case 0x15EC: arg = 1; break;
            case 0x15ED: arg = D_001427AC[0] != 0; break;
            case 0x15F0: arg = D_0014271C[0] != 0; break;
            case 0x15EF: arg = D_001D5576[0] != 0; break;
            case 0x15F1: arg = (D_00142C4C[0] & 0x8000) != 0; break;
            case 0x15F2: arg = (D_00142C5C[0] & 0x10000000) != 0; break;
            default:
                i++;
                continue;
            }
            row->x14 = func_L01_0049E9F0(arg);
            i++;
            break;
        }
    } while (D_L01_002ECBA8[i].x0 != 0);
}
