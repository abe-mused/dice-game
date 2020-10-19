// Abe Mused
//
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <time.h> 

#include "Date.h"
#include "Pants.h"
#include "Shirt.h"
#include "Outfit.h"
int displayMenu(){
	int choice;
	cout<<"Please choose from the following menu:"<<endl<<endl;
	cout<<"1: Select a random outfit"<<endl;
	cout<<"2: Select a shirt from a list"<<endl;
	cout<<"3: Select a pair of pants from a list"<<endl;
	cout<<"4: Replace a shirt from your wardrobe"<<endl;
	cout<<"5: Replace a pair of pants from your wardrobe"<<endl;
	cout<<"6: Quit and display weekly outfits"<<endl;
	cin>>choice;
		while(choice > 6 || choice < 1){
			cout<<"error, please choose one of the options displayed above: "<<endl;
			cin>>choice;
		}
	return choice;
}
int displayShirts(vector<Shirt> shirts){
	int choice;
	for(int i = 0; i <shirts.size(); i++){
		cout<<i+1<<") "<<shirts.at(i)<<endl;
	}
	cout<<endl<<"from the list above, enter the number of shirt you would like to wear: ";
	cin>>choice;
		while(choice > shirts.size() || choice < 1){
			cout<<"error, please choose one of the options displayed above: "<<endl;
			cin>>choice;
		}
	return choice;
}
int displayPants(vector<Pants> pants){
	int choice;
	for(int i = 0; i <pants.size(); i++){
		cout<<i+1<<") "<<pants.at(i)<<endl;
	}
	cout<<endl<<"from the list above, enter the number of the pair of pants you would like to wear: ";
	cin>>choice;
		while(choice > pants.size() || choice < 1){
			cout<<"error, please choose one of the options displayed above: "<<endl;
			cin>>choice;
		}
	return choice;
}
void displayOutfit(Shirt shirt, Pants pants){
	cout<<shirt<<" and "<<pants<<endl;
}
void replacePants(vector<Pants> &pants){
	Pants tempPants;
	int choice;
	for(int i = 0; i <pants.size(); i++){
		cout<<i+1<<") "<<pants.at(i)<<endl;
	}
	cout<<"from the list above, enter the number of the pair of pants you would like to replace: ";
	cin>>choice;
		while(choice > pants.size() || choice < 1){
			cout<<"error, please choose one of the options displayed above: "<<endl;
			cin>>choice;
		}
		getchar();
	cin>>tempPants;
	pants.at(choice-1) = tempPants;
}
void replaceShirt(vector<Shirt> &shirts){
	Shirt tempShirt;
	int choice;
	for(int i = 0; i <shirts.size(); i++){
		cout<<i+1<<") "<<shirts.at(i)<<endl;
	}
	cout<<"from the list above, enter the number of the shirt you would like to replace: ";
	cin>>choice;
		while(choice > shirts.size() || choice < 1){
			cout<<"error, please choose one of the options displayed above: "<<endl;
			cin>>choice;
		}
		getchar();
	cin>>tempShirt;
	shirts.at(choice-1) = tempShirt;
}





int main(int argc, char** argv) {
	srand (time(NULL));
	vector<Outfit> outfits;
	vector<Pants> pants;
	vector<Shirt> shirts;
	Shirt tempShirt;
	char subChoice;
	Pants tempPants;
	int choice, selectedShirtIndex = -1, selectedPantsIndex = -1, month, day, year, end = 1;
	
	cout<<"Enter your wardrobe of shirts:"<<endl<<endl;
	do{
		cin>>tempShirt;
		shirts.push_back(tempShirt);
		cout<<"Enter another shirt? y/n"<<endl;
		cin>>subChoice;
		getchar();
		subChoice = tolower(subChoice);
			while(subChoice != 'y' && subChoice != 'n'){
				cout<<"error, please enter y or n: "<<endl;
				cin>>subChoice;
				subChoice = tolower(subChoice);
				getchar();
			}
	}while(subChoice == 'y');
	
	cout<<"Enter your wardrobe of pants:"<<endl<<endl;
	do{
		cin>>tempPants;
		pants.push_back(tempPants);
		cout<<"Enter another pair of pants? y/n"<<endl;
		cin>>subChoice;
		getchar();
		subChoice = tolower(subChoice);
			while(subChoice != 'y' && subChoice != 'n'){
				cout<<"error, please enter y or n: "<<endl;
				cin>>subChoice;
				subChoice = tolower(subChoice);
				getchar();
			}
	}while(subChoice == 'y');
	
	do{
		selectedShirtIndex = -1;
		selectedPantsIndex = -1;
		
		while( (selectedShirtIndex == -1 || selectedPantsIndex == -1) && end !=0){
			
			system("cls");
			choice = displayMenu();
			switch(choice){
			case 1:
				selectedShirtIndex = rand() % (shirts.size());
				selectedPantsIndex = rand() % (pants.size());
				break;
			case 2:
				selectedShirtIndex = displayShirts(shirts) - 1;
				break;
			case 3:
				selectedPantsIndex = displayPants(pants) - 1;
				break;
			case 4:
				replaceShirt(shirts);
				break;
			case 5:
				replacePants(pants);
				break;
			case 6:

				for(Outfit outfit : outfits){
					cout<<outfit;
				}
				end = 0;

				break;
			}
		}
		if(end != 0){
			displayOutfit(shirts.at(selectedShirtIndex), pants.at(selectedPantsIndex));
			cout<<"do you want to add this to your weekly wardrobe? y/n"<<endl;
			cin>>subChoice;
			subChoice = tolower(subChoice);
				while(subChoice != 'y' && subChoice != 'n'){
					cout<<"error, please enter y or n: "<<endl;
					cin>>subChoice;
					subChoice = tolower(subChoice);
				}
			if(subChoice == 'y'){
				cout<<"What day are you wearing this outfit? MM DD YYYY"<<endl;
				cin>>month>>day>>year;
					while(month>12 || month < 1 || day > 31 || day < 1 || year < 2020){
						cout<<"error, please enter the data in the folloing format: MM DD YYYY"<<endl;
						cin>>month>>day>>year;
					}
				Outfit tempOutfit(month, day, year, pants.at(selectedPantsIndex).getColor(),
				pants.at(selectedPantsIndex).getStyle(), shirts.at(selectedShirtIndex).getColor(),
				shirts.at(selectedShirtIndex).getType());
				
				outfits.push_back(tempOutfit);	
			}
		}
	} while(end != 0);
	
	return 0;
}





ostream& operator<<(ostream& o, const Date date){
	cout<<date.month<<"/"<<date.day<<"/"<<date.year;
	return o;
}
ostream& operator<<(ostream& o, Pants pants){
	o<<pants.getColor()<<" "<<pants.getStyle();
	return o;
}
istream& operator>>(istream& in, Pants& pants){
	string temp;
	cout<<"please enter the color of the pants: "<<endl;
	getline(in,temp);
	pants.setColor(temp);
	cout<<"please enter the style of the pants: "<<endl;
	getline(in,temp);
	pants.setStyle(temp);
	return in;
}

ostream& operator<<(ostream& o, Shirt shirt){
	cout<<shirt.getColor()<<" "<<shirt.getType();
	return o;
}
istream& operator>>(istream& in, Shirt& shirt){
	string temp;
	cout<<"please enter the color of the shirt: "<<endl;
	getline(in,temp);
	shirt.setColor(temp);
	cout<<"please enter the type of the shirt: "<<endl;
	getline(in,temp);
	shirt.setType(temp);
	return in;
}

ostream& operator<<(ostream& o, Outfit outfit){
	cout<<outfit.getDate()<<endl<<outfit.getShirt()<<outfit.getPants();
	if(outfit.getShirt() == outfit.getPants()){
		cout<<"  This outfit matches!"<<endl;
	}else{
		cout<<"  Your shirt doesn't match your pants!"<<endl;
	}
	return o;
}
