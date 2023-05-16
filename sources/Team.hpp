#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <sstream>
#include <vector>
namespace ariel
{
    class Team
    {
    private:
        int participants;
        Character *chief;
        std::vector<Character *> Members;

    public:
        Team(Character *chief) : chief(chief)
        {
            if (chief->getIfPlayed() == true)
            {
                throw runtime_error("you cant Appointing the same captain to different teams");
            }
            participants = 1;
            Members.emplace_back(chief);
            chief->startPlay();
        }

        void add(Character *toAdd);
        virtual void attack(Team *otherTeam);
        int stillAlive();
        virtual void print();
        virtual Character *getChief() { return chief; }
        virtual vector<Character *> getMembers() { return Members; }
        virtual ~Team()
        {
            for (auto *member : Members)
            {
                delete member;
            }
            Members.clear();
        }
        // Because we wrote Distractor We need to add:
        // Copy constructor, shift constructor, copy operator, shift operator
        Team(const Team &other) : chief(other.chief)
        {
            for (auto *member : other.Members)
            {
                Members.push_back(member);
            }
        }

        Team &operator=(const Team &other)
        {
            if (this != &other)
            {
                delete chief;
                chief = (other.chief);
                for (auto *member : Members)
                {
                    delete member;
                }
                Members.clear();
                for (auto *member : other.Members)
                {
                    Members.push_back(member);
                }
            }
            return *this;
        }

        Team(Team &&other) noexcept
            : chief(other.chief), Members(std::move(other.Members))
        {
            other.chief = nullptr;
        }

        Team &operator=(Team &&other) noexcept
        {
            if (this != &other)
            {
                delete chief;
                chief = other.chief;
                other.chief = nullptr;

                for (auto *member : Members)
                {
                    delete member;
                }
                Members = std::move(other.Members);
            }
            return *this;
        }
    };

};
