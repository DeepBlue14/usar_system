#ifndef CONFIG_LST_CONTAINER_H
#define CONFIG_LST_CONTAINER_H

#include <QString>
#include <QStringList>

#include "JoyCmdTypes.h"

class ConfigLstContainer
{
    public:
        /**
         * Constructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         */
        ConfigLstContainer();
        
        /**
         * Mutator.
         * @see #descStrPtr
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: descStrPtr has been reset.<b></dd>
         *
         */
        void setDescStrPtr(QString* descStrPtr);
        
        /**
         * Accessor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return descStrPtr
         */
        QString* getDescStrPtr() const;
        
        /**
         * Mutator.
         * @see #strLstPtr
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: strLstPtr has been reset.<b></dd>
         *
         */
        void setStrLstPtr(QStringList* strLstPtr);
        
        /**
         * Accessor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return strLstPtr
         */
        QStringList* getStrLstPtr() const;
        
        /**
         * Mutator.
         * @see #cmd
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: cmd  has been reset. <b></dd>
         *
         */
        void setCmd(jct::Cmd cmd);
        
        /**
         * Accessor.
         * @see #cmd
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return cmd
         */
        jct::Cmd getCmd() const;
        
        /**
         * Gets the string representation (name) of an enumeration type.
         * @see #cmd
         * 
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return the name of a enum
         */
        const char* getCmdAsStr() const;
        
        /**
         * Classic Java-style toString() method.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: None.<b></dd>
         *
         * @return relevent data of the class
         */
        char* toString();
        
        /**
         * Destructor.
         *
         * <dt><b>Pre: None.<b></dd>
         * <dt><b>Post: Deletes the member variables of this class.<b></dd>
         */
        ~ConfigLstContainer();
        
    private:
        QString* descStrPtr; /**  */
        QStringList* strLstPtr;
        jct::Cmd cmd;
        
};

#endif /*  CONFIG_LST_CONTAINER_H */
