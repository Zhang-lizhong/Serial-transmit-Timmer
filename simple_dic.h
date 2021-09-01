#include <iostream>
#include "vector"
#include<string>


class simp_dict
{
public:

    struct item
    {
        string name = "";
        string val = "";
    };

    bool save_to(string addr)
    {
        file.open(addr, ios::out);
        if (!file.is_open())
        {
            file.close();
            return 0;
        }

        for (int i = 0; i < data.size(); i++)file << data[i].name << "   " << data[i].val << endl;
        file.close();
        return 1;

    }

    bool load_from(string addr)
    {

        file.open(addr, ios::in);
        if (!file.is_open())
        {
            file.close();
            return 0;
        }

        while (!file.eof())
        {
            item a;
            file >> a.name;
            if (file.eof())
            {
                file.close();
                return 0;
            }

            file >> a.val;
            data.push_back(a);
        }
        file.close();


        return 1;

    }

    void input(item in)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].name == in.name)
            {
                data[i] = in;
                return ;
            }
        }
        if (in.name == "" || in.val == "") return;
        data.push_back(in);
    }

    string get(string name)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].name == name)
            {
                return data[i].val;
            }
        }
        return "";

    }

private:
    fstream file;
    vector<item> data;

};
