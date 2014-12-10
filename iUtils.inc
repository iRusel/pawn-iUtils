// by Daniel_Cortez
// pro-pawn.ru
// Функция подсчитывает возраст игрока по введенным данным.
// Пример использования: GetAge(день, месяц, год) - получим возраст.
stock GetAge(day, month, year)
{
    new curday, curmonth, curyear;
    getdate(curyear, curmonth, curday);
    return curyear - year - _:(month>curmonth || month==curmonth && day>curday);
} 

// None
// None
// Функция определяет игрок находится в воде или нет.
// Пример использования: if(IsPlayerInWater) return - значит в воде.
stock IsPlayerInWater(playerid) 
{ 
    new Float:FXF_wpos[3]; 
    GetPlayerPos(playerid,FXF_wpos[0],FXF_wpos[1],FXF_wpos[2]); 
    if((FXF_wpos[2] > 0.00) || IsPlayerInZone(playerid,1808.2019,1424.5392,-2230.5024,-2347.7979)) return 0;
    else if((FXF_wpos[2] < 0.00) && (FXF_wpos[2] > -1.00)) return 1;
    else if(FXF_wpos[2] < -1.00) return 2;
    return 0; 
} 

// by SA-MP Team
// sa-mp.com
// Функция возвращает время в (сек\мс) которое игрок находится на сервере.
// Пример использования: PlayerOnlineTime(playerid) - вернет время в сек.
stock PlayerOnlineTime(targetid, ftime = 0)
{
	new time;
	if(!ftime) time = NetStats_GetConnectedTime(targetid)/1000;
	else ftime = NetStats_GetConnectedTime(targetid);
	return time;
}

// by Londlem
// pro-pawn.ru
// Функция создает строку сгенерированную из символов (русских, латинских).
// Пример использования: CreateRandomString(35, 1) - 35 рус.символов.
stock CreateRandomString(const len, const latin = 1)
{    
    new str[56], sl = !(1 <= len <= 55) ? 55 : len;    
    do
        str[--sl] = !latin ? (random(26) + 97) : (random(33) + 224);
    while(sl);
    return str;
}  

// by Daniel_Cortez
// pro-pawn.ru
// Возвращает размер стека.
stock GetStackSize()
{ 
    const    BYTES_TO_ADD = (cellbits/charbits);
    #emit    lctrl        2
    #emit    move.alt
    #emit    lctrl        3
    #emit    sub
    #emit    add.c        BYTES_TO_ADD
    #emit    retn
    return 0;
}