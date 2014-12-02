#include <iostream>

typedef int T;
namespace containers
{
    //    template<typename T>
    class node
    {
    public:
        node(const node& other)
            : value_(other.getValue())
            , prev_(other.getPrev())
            , next_(other.getNext())
        {}

        node()
            : value_()
            , prev_(NULL)
            , next_(NULL)
        {}

        ~node();

        T& getValue() const
        {
            return value_;
        }

        void setValue(const T& t)
        {
            value_ = t;
        }

        node* getPrev() const
        {
            return prev_;
        }

        const node* getPrev();

        node* getNext() const
        {
            return next_;
        }

        const node* getNext();

        bool isLast() const
        {
            return next_ == NULL;
        }

        /* friends */
        void setNext(node* next);
        void setPrev(node* prev);
    private:
        T value_;
        node* prev_;
        node* next_;
    };

    //    template<typename T>
    class au_list
    {
        au_list()
            : size_(0)
            , begin_(NULL)
            , end_(NULL)
        {}

        au_list(au_list& list)
            : size_(list.size_)
        {
            auto news = std::vector<node*>;
            {
                node* n = list.begin_;
                for(; !n->isLast(); n = n->getNext())
                {
                    node* new_n = new node();
                    new_n->setValue(n->getValue());
                    news.push_back(new_n);
                }
            }
            size_ = news.size();
            for(size_t i = 1; i < size_; ++i)
            {
                node* node = news[i];
                node->setPrev(news[i - 1]);
                if (i != size_ - 1)
                {
                    node->setNext(news[i + 1]);
                }
            }
            begin_ = news[0];
            end_ = news[size_ - 1]->getNext();
        }

        ~au_list()
        {
            {
                node* n = begin_;
                node* tmp = n;
                while(tmp != NULL)
                {
                    tmp = n->getNext();
                    delete n;
                }
            }
        }

        bool empty() const
        {
            return size_ == 0;
        }

        void clear()
        {
            auto todel = std::vector<node>();
            {
                node* n = begin_;
                for (; n != end_; n = n->getNext())
                {
                    todel.push_back(*n);
                }
            }
            for (size_t i = 0; i < size_; ++i)
            {
                delete todel[i];
            }
            size_ = 0;
        }

        node* begin()
        {
            return begin_;
        }

        node* end()
        {
            return end_;
        }

        size_t size() const
        {
            return size_ * sizeof(T);
        }

        node* insert(node* pos, const T& val)
        {}

        node* erase(node* pos)
        {
            node* prev = pos->getPrev();
            node* next = pos->getNext();

            prev.setNext(next);
            next.setPrev(prev);
            delete pos;
        }

        node* erase(node* first, node* last)
        {
            for (; first != last; first = first->getNext())
            {
                erase(first);
            }
        }

        friend void setNext(node* next)
        {
            this.next_ = next;
        }

        friend void setPrev(node* prev)
        {
            this.prev_ = prev;
        }

    private:
        size_t size_;
        node* begin_;
        node* end_;
    };
};
