#include <iostream>
#include <string>

class LGBT
{
protected:
    std::string name;
    int rarity; 
    std::string clothes;
public:
    virtual ~LGBT() = default; 


    void setRarity(int level_of_rarity) { rarity = level_of_rarity; }
    void setName(std::string name_of_type) { name = name_of_type; }
    void setClothes(std::string name_of_clothes) { clothes = name_of_clothes; }

    virtual void SaySomething()
    {
        std::cout << "ЯЛКВМОМ" << std::endl;
    }

    void displayInfo()
    {
        std::cout << "I am a " << rarity << " rarity, my name is " << name << " and I am wearing " << clothes << std::endl;
    }
};

class Gay : public LGBT
{
public:
    Gay()
    {
        setRarity(4);
        setName("Joey Mills");
        setClothes("Strip Club Outfit");
    }
    
    void SaySomething() override
    {
        std::cout << "I am a gay! I like men" << std::endl;
    }
};

class Lesbian : public LGBT
{
public:
    Lesbian()
    {
        setRarity(4);
        setName("Zoe");
        setClothes("Pink Dress");
    }
    void SaySomething() override
    {
        std::cout << "I am a Lesbian! Scissors is the best" << std::endl;
    }
};

class Twink : public Gay
{
protected:
    std::string type;
public:
    void SelectType(std::string type_of_twink)
    {
        type = type_of_twink;
    }
    void SelectType()
    {
        type = "classic twink";
    }

    Twink(std::string twink_type)
    {
        SelectType(twink_type);
    }
    Twink() {}

    void SaySomething() override
    {
        std::cout << "I am a " << type << " twink!" << std::endl;
    }
};

class Femboy: public Twink
{
    std::string OF;
    std::string pronouns;
public:
    void setOF(std::string OF_link) { OF = OF_link; }
    void setPronouns(std::string pronouns_of_femboy) { pronouns = pronouns_of_femboy; }

    Femboy(std::string OF_link, std::string pronouns_of_femboy, std::string twink_type)
     : Twink(twink_type)
    {
        setOF(OF_link);
        setRarity(5);
        setPronouns(pronouns_of_femboy);
    }
    
    void SaySomething() override
    {
        std::cout << "UWU :3" << std::endl;
        std::cout <<"My OF is " << OF << " and my pronouns are " << pronouns << std::endl;

    }
};

int main()
{
LGBT* characters[3];
    
characters[0] = new Femboy("@femboy.szn", "he/him/they", "short-haired");
characters[1] = new Gay();
characters[2] = new Lesbian();
    
for (int i = 0; i < 3; i++)
{
    characters[i]->displayInfo();
    characters[i]->SaySomething(); 
    std::cout << "_______________________________________" << std::endl;
}

for (int i = 0; i < 3; i++)
{
    delete characters[i];
}
    
return 0;
};