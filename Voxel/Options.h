#ifndef OPTIONS_H
#define OPTIONS_H

class Options
{
public:
    Options();
    ~Options();

    static Options* getOptionsManager();

    void setDown(int down)
    {
        this->down = down;
    }

    void setUp(int up)
    {
        this->up = up;
    }
    int getDown() const
    {
        return down;
    }
    int getUp() const
    {
        return up;
    }

    void setLeft(int left)
    {
        this->left = left;
    }
    void setRight(int right)
    {
        this->right = right;
    }
    int getLeft() const
    {
        return left;
    }
    int getRight() const
    {
        return right;
    }

private:
    static Options* opt;
    int up = 'w';
    int down = 's';
    int left = 'a';
    int right = 'd';
};

#endif // OPTIONS_H
