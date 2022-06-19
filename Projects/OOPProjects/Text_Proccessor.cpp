#include<iostream>
#include<fstream>
using namespace std;

class Character
{
private:
	char* single_character;
public:
	Character()
	{
		this->single_character = nullptr;
	}
	Character(Character& c)
	{
		this->single_character = new char;
		*(this->single_character) = *(c.single_character);
	}
	Character(char* c)
	{
		this->single_character = new char;
		*(this->single_character) = *(c);
	}
	void set_character(char* c)
	{
		this->single_character = new char;
		*(this->single_character) = *(c);
	}
	char* get_character()
	{
		return this->single_character;
	}
	void Display()
	{
		cout << this->single_character;
	}
	Character operator =(Character obj)
	{
		this->single_character = new char;
		*this->single_character = *obj.single_character;
		return *this;
	}
	Character operator =(char c)
	{
		this->single_character = new char;
		*this->single_character = c;
		return *this;
	}
	bool operator !=(char c)
	{
		if (*this->single_character != c)
		{
			return true;
		}
		return false;
	}
	~Character()
	{
		delete[] this->single_character;
	}
};

class Word
{
private:
    Character* the_characters;
public:
    Word()
    {
        this->the_characters = nullptr;
    }
    /*Word(Character* & C)
    {
        my_str_cpy(this->the_characters, obj.);
    }*/
    Word(char* w)
    {
        my_str_cpy(this->the_characters, w);
    }

    void my_str_cpy(Character* & C, char* b)
    {
        int str_length = 0;
        for (int k = 0; b[k] != '\0'; k++)
        {
            str_length++;
        }
        C = new Character[str_length + 1];
        for (int k = 0; k < str_length + 1; k++)
        {
            C[k] = b[k];
        }
    }

    void print_word()
    {

        for (int i = 0; this->the_characters[i] != '\0'; i++)
        {
            this->the_characters[i].Display();
        }
        cout << endl;
    }

    void my_setter_for_word(char* w)
    {
        my_str_cpy(this->the_characters, w);
    }
    char* my_getter_for_word()
    {
        int str_length = 0;
        for (int i = 0; this->the_characters[i] != '\0'; i++)
        {
            str_length++;
        }
        char* a = new char[str_length + 1];
        for (int i = 0; i < str_length + 1; i++)
        {
            a[i] = *this->the_characters[i].get_character();
        }
        return a;
    }
};

class Sentence
{
private:
    Word* The_Words_List_In_Sentence;
    int Counter_Current_Words_List;
public:
    Sentence()
    {
        this->The_Words_List_In_Sentence = nullptr;
        this->Counter_Current_Words_List = 0;
    }

    /*Sentence(Word* L,int c)
    {
        this->The_Words_List_In_Sentence = new Word[c];
        for (int i = 0; i < c; i++)
        {
            The_Words_List_In_Sentence[i].setterword(L[i].getterword());
        }
    }*/

    void set_word(char* w)
    {
        this->The_Words_List_In_Sentence[this->Counter_Current_Words_List++].my_setter_for_word(w);
    }


    char* special_get_word(int i)
    {
        return this->The_Words_List_In_Sentence[i].my_getter_for_word();
    }
    void special_set_word(int j, char* ptr)
    {
        this->The_Words_List_In_Sentence[j].my_setter_for_word(ptr);
    }

    int my_get_index()
    {
        return this->Counter_Current_Words_List;
    }

    void my_set_word_length(int l)
    {
        this->The_Words_List_In_Sentence = new Word[l];
        this->Counter_Current_Words_List = 0;
    }

    void my_set_sentence(Word* L, int c)
    {
        this->The_Words_List_In_Sentence = new Word[c];
        for (int i = 0; i < c; i++)
        {
            The_Words_List_In_Sentence[i].my_setter_for_word(L[i].my_getter_for_word());
        }
        this->Counter_Current_Words_List = c;
    }

    Word* my_get_words_list()
    {
        return this->The_Words_List_In_Sentence;
    }

};

class Paragraph
{
private:
	Sentence* The_Sentences_List;
	int Counter_Current_Sentences_List;
	friend ofstream& operator <<(ofstream& fout, Paragraph& C);
	friend ifstream& operator >>(ifstream& fin, Paragraph& C);
	friend ostream& operator<< (ostream& out, Paragraph& B);

public:
	Paragraph()
	{
		this->The_Sentences_List = nullptr;
		this->Counter_Current_Sentences_List = 0;
	}

	Paragraph(Sentence* L, int c)
	{
		this->The_Sentences_List = new Sentence[c];
		for (int i = 0; i < c; i++)
		{
			The_Sentences_List[i].my_set_sentence(L[i].my_get_words_list(), L[i].my_get_index());
		}
	}

	//c
	bool check_if_para_is_lowercase()
	{
		for (int i = 0; i < this->Counter_Current_Sentences_List; i++)
		{
			int count = this->The_Sentences_List[i].my_get_index();
			for (int j = 0; j < count; j++)
			{
				char* ptr = this->The_Sentences_List[i].special_get_word(j);
				for (int k = 0; ptr[k] != '\0'; k++)
				{
					if (ptr[k] >= 65 || ptr[k] <= 90)
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	//c
	void set_word_in_sen(char* w)
	{
		this->The_Sentences_List[this->Counter_Current_Sentences_List].set_word(w);
	}

	//c
	void my_freq_writer(fstream & file, int i)
	{
		if (file.is_open())
		{
			file << "Paragraph number :" << i << endl;
			file << "Sentences in Paragraph " << i << ":" << this->Counter_Current_Sentences_List << endl;
			for (int i = 0; i < this->Counter_Current_Sentences_List; i++)
			{
				file << "Words in Sentence no " << i + 1 << ":" << this->The_Sentences_List[i].my_get_index() << endl;
				for (int j = 0; j < this->The_Sentences_List[i].my_get_index(); j++)
				{
					file << "Characters in word no " << j + 1 << " of sentence no " << i + 1 << ":" << para_get_str_length(this->The_Sentences_List[i].special_get_word(j)) << endl;
				}
			}
		}

	}


	Paragraph operator +(Paragraph& P)
	{
		Paragraph Third;

		int len = this->Counter_Current_Sentences_List + P.Counter_Current_Sentences_List;

		Third.The_Sentences_List = new Sentence[len];
		Third.Counter_Current_Sentences_List = 0;

		int index = 0;
		for (int i = 0; i < this->Counter_Current_Sentences_List; i++)
		{
			Third.The_Sentences_List[index++].my_set_sentence(this->The_Sentences_List[i].my_get_words_list(), this->The_Sentences_List[i].my_get_index());
		}
		for (int i = 0; i < P.Counter_Current_Sentences_List; i++)
		{
			Third.The_Sentences_List[index++].my_set_sentence(P.The_Sentences_List[i].my_get_words_list(), P.The_Sentences_List[i].my_get_index());
		}
		Third.Counter_Current_Sentences_List = index;

		return Third;
	}

	Paragraph operator++(int a)
	{
		Paragraph Para = *this;
		if (!this->check_if_para_is_uppercase())
		{
			int length = 0;
			char* word = nullptr;

			for (int a = 0; a < this->Counter_Current_Sentences_List; a++)
			{
				length = this->The_Sentences_List[a].my_get_index();
				for (int b = 0; b < length; b++)
				{
					word = this->The_Sentences_List[a].special_get_word(b);
					for (int c = 0; word[c] != '\0'; c++)
					{
						if (word[c] >= 97 && word[c] <= 122 )
						{
							word[c] = word[c] - 32;
						}
					}
					this->The_Sentences_List[a].special_set_word(b, word);
				}
			}
		}
		return Para;
	}

	Paragraph operator--(int a)
	{
		Paragraph Para = *this;

		if (!this->check_if_para_is_lowercase())
		{
			int length = 0;
			char* word = nullptr;
			for (int a = 0; a < this->Counter_Current_Sentences_List; a++)
			{
				length = this->The_Sentences_List[a].my_get_index();
				for (int b = 0; b < length; b++)
				{
					word = this->The_Sentences_List[a].special_get_word(b);
					for (int c = 0; word[c] != '\0'; c++)
					{
						if (word[c] >= 65 && word[c] <= 90)
						{
							word[c] = word[c] + 32;
						}
					}
					this->The_Sentences_List[a].special_set_word(b, word);
				}
			}
		}
		return Para;
	}

	Paragraph operator*(int enc_key)
	{
		int length = 0;
		char* word = nullptr;
		for (int a = 0; a < this->Counter_Current_Sentences_List; a++)
		{
			length = this->The_Sentences_List[a].my_get_index();
			for (int b = 0; b < length; b++)
			{
				word = this->The_Sentences_List[a].special_get_word(b);
				for (int c = 0; word[c] != '\0'; c++)
				{
					word[c] = word[c] - enc_key;
				}
				this->The_Sentences_List[a].special_set_word(b, word);
			}
		}
		return *this;
	}

	Paragraph operator%(int enc_key)
	{
		int length = 0;
		char* word = nullptr;
		for (int a = 0; a < this->Counter_Current_Sentences_List; a++)
		{
			length = this->The_Sentences_List[a].my_get_index();
			for (int b = 0; b < length; b++)
			{
				word = this->The_Sentences_List[a].special_get_word(b);
				for (int c = 0; word[c] != '\0'; c++)
				{
					word[c] = word[c] + enc_key;
				}
				this->The_Sentences_List[a].special_set_word(b, word);
			}
		}
		return *this;
	}

	void para_set_word_length(int l)
	{
		this->The_Sentences_List[this->Counter_Current_Sentences_List].my_set_word_length(l);
	}

	int para_get_str_length(char* str)
	{
		int length = 0;
		for (int k = 0; str[k] != '\0'; k++)
			length++;
		return length;
	}

	bool check_if_para_is_uppercase()
	{
		for (int i = 0; i < this->Counter_Current_Sentences_List; i++)
		{
			int count = this->The_Sentences_List[i].my_get_index();
			for (int j = 0; j < count; j++)
			{
				char* ptr = this->The_Sentences_List[i].special_get_word(j);
				for (int k = 0; ptr[k] != '\0'; k++)
				{
					if (ptr[k] >= 97 || ptr[k] <= 122)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
};

ifstream& operator >>(ifstream& fileinput, Paragraph& Par)
{
	char par[500];
	char buffer[500];
	int count = 0;
	char Sen[200];
	int in = 0;

	if (fileinput.is_open())
	{
		while (!fileinput.eof())
		{
			fileinput.getline(buffer, 500);

			for (int a = 0; buffer[a] != '\0'; a++)
			{
				par[count++] = buffer[a];
				if (buffer[a + 1] == '\0')
				{
					par[count++] = '\n';
				}
			}
		}


		int len = 0;
		for (int a = 0; par[a] != '\0'; a++)
		{
			if (par[a] == '.')
			{
				len++;
			}
		}

		Par.Counter_Current_Sentences_List = 0;
		Par.The_Sentences_List = new Sentence[len];

		for (int a = 0; par[a] != '\0'; a++)
		{
			if (par[a] != '.')
			{
				Sen[in++] = par[a];
			}
			else
			{
				Sen[in] = '\0';
				int wordlength = 1;
				for (int b = 0; Sen[b] != '\0'; b++)
				{
					if (Sen[b] == ' ' || Sen[b] == '\n')
					{
						wordlength++;
					}
				}
				//
				Par.para_set_word_length(wordlength);
				char myword[20];
				int index_for_word = 0;
				for (int k = 0; Sen[k] != '\0'; k++)
				{
					if (Sen[k] != ' ')
					{
						myword[index_for_word++] = Sen[k];
					}
					if (Sen[k] == ' ' || Sen[k + 1] == '\0' || Sen[k] == '\n')
					{
						myword[index_for_word] = '\0';
						index_for_word = 0;
						Par.set_word_in_sen(myword);
					}
				}
				Par.Counter_Current_Sentences_List++;
				in = 0;
			}
		}
	}
	return fileinput;
}

ofstream& operator <<(ofstream& fileout, Paragraph& Par)
{
	int length = 0;
	char* word = nullptr;
	int last = 0;
	if (fileout.is_open())
	{
		for (int a = 0; a < Par.Counter_Current_Sentences_List; a++)
		{
			length = Par.The_Sentences_List[a].my_get_index();
			for (int b = 0; b < length; b++)
			{
				word = Par.The_Sentences_List[a].special_get_word(b);
				last = 0;
				for (int c = 0; word[c] != '\0'; c++)
				{
					fileout << word[c];
					last = c;
				}
				if (b + 1 != length && word[last] != '\n')
				{
					fileout << " ";
				}
			}
			fileout << '.';
		}
	}
	fileout.close();
	return fileout;
}

ostream& operator<< (ostream& out, Paragraph& Par)
{
	int length = 0;
	char* word = nullptr;
	for (int a = 0; a < Par.Counter_Current_Sentences_List; a++)
	{

		length = Par.The_Sentences_List[a].my_get_index();

		for (int b = 0; b < length; b++)
		{

			word = Par.The_Sentences_List[a].special_get_word(b);
			int last = 0;
			for (int c = 0; word[c] != '\0'; c++)
			{
				cout << word[c];
				last = c;
			}
			if (b + 1 != length && word[last] != '\n')
			{
				cout << " ";
			}
		}

		cout << '.';
	}
	return out;
}

int main()
{
	Paragraph P1, P2;

	cout << "\n*********************  Reading Paragrpah A  **********************\n" << endl;
	ifstream first("paragraphA.txt");
	first >> P1;
	ofstream write_first("testing.txt", 'w');
	write_first << P1;

	cout << "\n****************************  Paragraph A  *****************************\n\n" << P1 << endl;


	cout << "\n********************  Converting into Upper Case  **********************\n" << endl;
	P1++;
	cout << P1 << endl;

	cout << "\n*********************  Converting into Lower Case  **********************\n" << endl;
	P1--;
	cout << P1 << endl;


	cout << "\n*********************  Reading Paragrpah B  **********************\n" << endl;
	ifstream second("paragraphB.txt");
	second >> P2;
	cout << "\n**************************  Paragraph B  ***************************\n\n" << P2 << endl;


	Paragraph P3 = P1 + P2;
	cout << "\n\n**********************************  Addition of Paragraph A&B  ********************************** \n\n" << P3 << endl;


	P1 = P1 % 3;
	cout << "\n******************************  After Encrypting Paragraph A ******************************\n\n" << P1 << endl;

	P1 = P1 * 3;
	cout << "\n*******************************  After Decrypting Paragraph A  ******************************\n\n" << P1 << endl;

	cout << "\n\n********************** Frequency.txt has been Updated ***************************** " << endl;
	char frequency_file_name[] = "Frequency.txt";
	fstream file(frequency_file_name, 'w');
	P1.my_freq_writer(file, 1);
	P2.my_freq_writer(file, 2);



	return 0;
}
