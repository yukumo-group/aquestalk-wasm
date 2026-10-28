char __fastcall sub_180005514(__int64 a1, __int64 a2, int a3, int a4)
{
  char result; // al

  result = a4 - 1;
  if ( (unsigned int)(a4 - 1) <= 3 )
  {
    result = a3 - 1;
    if ( (unsigned int)(a3 - 1) <= 0xE )
    {
      result = byte_18002EE60[5 * a3 + a4];
      if ( result == 1 )
      {
        if ( *(_BYTE *)a2 == 119 && *(_BYTE *)(a2 + 1) == 97 )
        {
          *(_WORD *)a2 = 24930;
        }
        else
        {
          switch ( *(_BYTE *)a2 )
          {
            case 'H':
              *(_BYTE *)a2 = 66;
              break;
            case 'K':
              *(_BYTE *)a2 = 86;
              break;
            case 'S':
            case 'c':
              *(_BYTE *)a2 = 106;
              break;
            case 'h':
              *(_BYTE *)a2 = 98;
              break;
            case 'k':
              *(_BYTE *)a2 = 118;
              break;
            case 's':
              *(_BYTE *)a2 = 122;
              break;
            case 't':
              *(_BYTE *)a2 = 100;
              break;
          }
        }
      }
      else
      {
        if ( result != 2 )
          return result;
        switch ( *(_BYTE *)a2 )
        {
          case 'w':
            if ( *(_BYTE *)(a2 + 1) == 97 )
            {
              *(_WORD *)a2 = 24944;
              return result;
            }
            break;
          case 'H':
            *(_BYTE *)a2 = 80;
            break;
          case 'h':
            *(_BYTE *)a2 = 112;
            break;
          default:
            if ( *(_BYTE *)a2 == 102 && *(_BYTE *)(a2 + 1) == 117 )
            {
              *(_WORD *)a2 = 30064;
              return result;
            }
            break;
        }
      }
    }
  }
  return result;
}