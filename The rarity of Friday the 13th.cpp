#include <iostream>

int namNhuan(int n){ //Kiểm tra năm n có là năm nhuận hay không
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) return 1;
	return 0;
}

int demNgay(int ngay, int thang, int nam){ //Đếm số ngày từ 1/1/1900 tới ngay/thang/nam
	int songay = 0;
	for (int i = 1900; i < nam; i++){
		if(namNhuan(i)) songay += 366;	
	 	else songay += 365;
	}
	for (int i = 1; i < thang; i++){
		switch (i){
			case 4:
			case 6:
			case 9:
			case 11:
			 	songay += 30;
			 	break;
	 		case 2:
	 			if (namNhuan(nam)) songay += 29;
	 			else songay += 28;
	 			break;
			default:
				songay += 31;
				break;
		}
	}
	return songay + ngay;	
}

void bangthu6ngay13 (int N){
	int i, j, songay;
	int thuhai = 0, thuba = 0, thutu = 0, thunam = 0, thusau = 0, thubay = 0, chunhat = 0;
	for (i = 1900; i <= 1900 + N - 1; i++){ //Xét từ năm 1900 tới năm 1900 + N - 1
		for (j = 1; j <= 12; j++){          //Mỗi năm xét từng tháng
			songay = demNgay(13, j, i);     //Đếm số ngày từ 1/1/1900 tới 13/j/i
			switch (songay % 7){            //Lấy số ngày % 7 để kiểm tra ngày 13/j/i là thứ mấy
				case 0: chunhat++; 	break;  //Nếu số ngày % 7 == 0 thì hôm đó là chủ nhật
				case 1: thuhai++; 	break;  //___________________1_______________thứ hai
				case 2: thuba++;	break;  //___________________2__________________ ba
				case 3: thutu++;	break;  //___________________3__________________ tư
				case 4: thunam++;	break;  //___________________4__________________ năm
				case 5: thusau++;	break;  //___________________5__________________ sáu
				case 6: thubay++;	break;  //___________________6__________________ bảy
			}
		}
	}
	cout << thubay << " " << chunhat << " " << thuhai << " " << thuba << " " << thutu << " " << thunam << " " << thusau << endl;
	// In ra số lần ngày 13 rơi vào các ngày thứ 7, chủ nhật, thứ 2, 3, 4, 5, 6 từ ngày 1/1/1900 tới ngày 31/12/1900+N-1
}

int main(){
	int N;
	cout << "Nhap N: ";
	cin >> N;
	bangthu6ngay13(N);
}