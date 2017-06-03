#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

const int DEFAULT_TABLE_SIZE = 128;

template <class type>
class LinkedHashEntry
{
private:
    int key;
    type* value;
    LinkedHashEntry *next;
public:
    LinkedHashEntry(int key, type* value)
    {
        this->key = key;
        this->value = new type(*value);
        this->next = NULL;
    }

    ~LinkedHashEntry()
    {
        delete value;
    }

    int getKey()
    {
        return key;
    }

    type* getValue()
    {
        return value;
    }

    void setValue(type* value)
    {
        this->value = value;
    }

    LinkedHashEntry *getNext()
    {
        return next;
    }

    void setNext(LinkedHashEntry *next)
    {
        this->next = next;
    }
};

template <class type>
class HashTable
{
private:
    float threshold;
    int maxSize;
    int tableSize;
    int size;
    LinkedHashEntry<type> **table;

    void resize()
    {
        int oldTableSize = tableSize;
        tableSize *= 2;
        maxSize = (int) (tableSize * threshold);
        LinkedHashEntry<type> **oldTable = table;
        table = new LinkedHashEntry<type>*[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = NULL;
        size = 0;
        for (int hash = 0; hash < oldTableSize; hash++)
            if (oldTable[hash])
            {
                LinkedHashEntry<type> *oldEntry;
                LinkedHashEntry<type> *entry = oldTable[hash];
                while (entry)
                {
                    insert(entry->getKey(), entry->getValue());
                    oldEntry = entry;
                    entry = entry->getNext();
                    delete oldEntry;
                }
            }
        delete[] oldTable;
    }

public:
    HashTable()
    {
        threshold = 0.75f;
        maxSize = 96;
        tableSize = DEFAULT_TABLE_SIZE;
        size = 0;
        table = new LinkedHashEntry<type>*[tableSize];
        for (int i = 0; i < tableSize; i++)
            table[i] = NULL;
    }

    void setThreshold(float threshold)
    {
        this->threshold = threshold;
        maxSize = (int) (tableSize * threshold);
    }

    type* find(int key)
    {
        int hash = (key % tableSize);
        if (!table[hash])
            return NULL;
        else
        {
            LinkedHashEntry<type> *entry = table[hash];
            while (entry && entry->getKey() != key)
                entry = entry->getNext();
            if (!entry)
                return NULL;
            else
                return entry->getValue();
        }
    }

    void insert(int key, type* value)
    {
        int hash = (key % tableSize);
        if (!table[hash])
        {
            table[hash] = new LinkedHashEntry<type>(key, value);
            size++;
        }
        else
        {
            LinkedHashEntry<type> *entry = table[hash];
            while (entry->getNext())
                entry = entry->getNext();
            if (entry->getKey() == key)
                entry->setValue(value);
            else
            {
                entry->setNext(new LinkedHashEntry<type>(key, value));
                size++;
            }
        }
        if (size >= maxSize)
            resize();
    }

    void remove(int key)
    {
        int hash = (key % tableSize);
        if (table[hash])
        {
            LinkedHashEntry<type> *prevEntry = NULL;
            LinkedHashEntry<type> *entry = table[hash];
            while (entry->getNext() && entry->getKey() != key)
            {
                prevEntry = entry;
                entry = entry->getNext();
            }
            if (entry->getKey() == key)
            {
                if (!prevEntry)
                {
                    LinkedHashEntry<type> *nextEntry = entry->getNext();
                    delete entry;
                    table[hash] = nextEntry;
                }
                else
                {
                    LinkedHashEntry<type> *next = entry->getNext();
                    delete entry;
                    prevEntry->setNext(next);
                }
                size--;
            }
        }
    }

    ~HashTable()
    {
        for (int hash = 0; hash < tableSize; hash++)
        {
            if (table[hash])
            {
                LinkedHashEntry<type> *prevEntry = NULL;
                LinkedHashEntry<type> *entry = table[hash];
                while (entry)
                {
                    prevEntry = entry;
                    entry = entry->getNext();
                    delete prevEntry;
                }
            }
        }
        delete[] table;
    }
};

#endif // HASHTABLE_H_INCLUDED
