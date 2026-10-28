__int64 __fastcall sub_180005774(__int64 *a1, char *a2, char *a3, _DWORD *a4)
{
  char *v7; // rcx
  char *v8; // rcx
  char *v9; // rdx
  char *v11; // rcx
  char *v12; // rcx
  char *v13; // rcx
  char *v14; // rcx
  char *v15; // rcx
  char *v16; // rcx
  char *v17; // rcx
  char *v18; // rcx
  char *v19; // rcx
  char *v20; // rcx
  char *v21; // rcx
  char *v22; // rcx

  *a4 = 0;
  if ( a3 && *a3 )
  {
    if ( (unsigned int)sub_180001348(a3, byte_180030128) )
    {
      if ( !(unsigned int)sub_180001348(v7, byte_180030138) )
      {
        while ( *a2 == 48 )
          ++a2;
        if ( !(unsigned int)sub_180001348(a2, "1") )
        {
          v9 = (char *)&unk_18002E364;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v11, "2") )
        {
          v9 = (char *)&unk_18002DFF0;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v12, "3") )
        {
          v9 = (char *)&unk_18002DFF4;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v13, "4") )
        {
          v9 = (char *)&unk_18002EEC0;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v14, "5") )
        {
          v9 = (char *)&unk_18002EE50;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v15, "6") )
        {
          v9 = (char *)&unk_18002EEC4;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v16, "7") )
        {
          v9 = (char *)&unk_18002DFEC;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v17, "8") )
        {
          v9 = (char *)&unk_18002EE4C;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v18, "9") )
        {
          v9 = (char *)&unk_18002EEB0;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v19, "10") )
        {
          v9 = (char *)&unk_18002EE58;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v20, "14") )
        {
          v9 = (char *)&unk_18002EF4C;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v21, "20") )
        {
          v9 = (char *)&unk_18002EE54;
          goto LABEL_6;
        }
        if ( !(unsigned int)sub_180001348(v22, "24") )
        {
          v9 = (char *)&unk_18002EE40;
          goto LABEL_6;
        }
      }
    }
    else
    {
      if ( !(unsigned int)sub_180001348(a2, "1") )
      {
        v9 = (char *)&unk_18002EEB8;
LABEL_6:
        *a4 = sub_1800019F8(*a1, v9);
        return 1;
      }
      if ( !(unsigned int)sub_180001348(v8, "2") )
      {
        v9 = (char *)&unk_18002EEE8;
        goto LABEL_6;
      }
    }
  }
  return 0;
}