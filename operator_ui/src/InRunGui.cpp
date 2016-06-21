#include "../include/operator_ui/InRunGui.h"


InRunGui::InRunGui(QWidget* parent) : QWidget(parent)
{
    titlePtr = new QLabel("<b>Select file type</b>");
    
    langStrPtr = new QString("null");
    fileTypeStrPtr = new QString("null");
    
    langsStrLstPtr = new QVector<QListWidgetItem*>();
    langsStrLstPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/compass.png"), "Map") );
    langsStrLstPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/robot.png"), "Robot") );
    langsStrLstPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/target.png"), "Gun") );
    langsStrLstPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/voice.png"), "Voice") );
    langsStrLstPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/autonomy.png"), "Autonomy") );
    
    
    
    cFileOptLstWidPtrVecPtr = new QVector<QListWidgetItem*>();
    cFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/selected.png"),
                                                                 "Olsen Hall 3rd floor") );
    cFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("res/not_selected.png"),
                                                                 "Olsen Hall 4th floor") );

    cppFileOptLstWidPtrVecPtr = new QVector<QListWidgetItem*>();
    cppFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/selected.png"),
                                                             "RGB") );
    cppFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "IR") );
    
    pythonFileOptLstWidPtrVecPtr = new QVector<QListWidgetItem*>();
    pythonFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "RGB") );
    pythonFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/selected.png"),
                                                             "TARGET") );
    
    javaFileOptLstWidPtrVecPtr = new QVector<QListWidgetItem*>();
    javaFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "Duplex") );
    javaFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/selected.png"),
                                                             "Off") );
    javaFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "Input only") );
    javaFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "Output only") );
    
    lispFileOptLstWidPtrVecPtr = new QVector<QListWidgetItem*>();
    lispFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/selected.png"),
                                                             "Full teleop") );
    lispFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "Auto drive") );
    lispFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "Auto shoot") );
    lispFileOptLstWidPtrVecPtr->push_back(new QListWidgetItem(QIcon("src/usar_teleop/operator_ui/res/not_selected.png"),
                                                             "Full Auto") );
   
    
    langsLwPtr = new QListWidget();
    langsLwPtr->viewport()->setAutoFillBackground( false );
    //langsLwPtr->addItems(*langsStrLstPtr);
    for(size_t i = 0; i < langsStrLstPtr->size(); i++)
    {
        langsLwPtr->addItem(langsStrLstPtr->at(i) );
        langsLwPtr->item(i)->setBackground(Qt::transparent);
    }
    //langsLwPtr->item(0)->setSelected(true);
    connect(langsLwPtr, SIGNAL(itemSelectionChanged() ), this, SLOT(handleSwapOptionsSlot() ) );
    
    fileTypeStrLstPtrVec = new QVector<QVector<QListWidgetItem*>*>();
    fileTypeStrLstPtrVec->push_back(cFileOptLstWidPtrVecPtr);
    fileTypeStrLstPtrVec->push_back(cppFileOptLstWidPtrVecPtr);
    fileTypeStrLstPtrVec->push_back(pythonFileOptLstWidPtrVecPtr);
    fileTypeStrLstPtrVec->push_back(javaFileOptLstWidPtrVecPtr);
    fileTypeStrLstPtrVec->push_back(lispFileOptLstWidPtrVecPtr);
    
    fileTypeLwPtr = new QListWidget();
    fileTypeLwPtr->viewport()->setAutoFillBackground( false );
    //fileTypeLwPtr->addItems(*(fileTypeStrLstPtrVec.at(0)) ); // default
    
    for(size_t i = 0; i < fileTypeStrLstPtrVec->at(0)->size(); i++)
    {
        fileTypeLwPtr->addItem(new QListWidgetItem(*fileTypeStrLstPtrVec->at(0)->at(i)) ); // default
        fileTypeLwPtr->item(i)->setBackground(Qt::transparent);
    }
    

    outerLayoutPtr = new QGridLayout();
    outerLayoutPtr->addWidget(titlePtr, 0, 0, 1, 2, Qt::AlignHCenter);
    outerLayoutPtr->addWidget(langsLwPtr, 1, 0);
    outerLayoutPtr->addWidget(fileTypeLwPtr, 1, 1);

    this->setLayout(outerLayoutPtr);
}


void InRunGui::handleSwapOptionsSlot()
{
    fileTypeLwPtr->clear(); // Remove old items (actually, it deletes them totally--not just form the UI)
    
    for(size_t i = 0; i < fileTypeStrLstPtrVec->at(langsLwPtr->currentRow())->size(); i++)
    {
        fileTypeLwPtr->addItem(new QListWidgetItem(*fileTypeStrLstPtrVec->at(langsLwPtr->currentRow())->at(i)) );
        fileTypeLwPtr->item(i)->setBackground(Qt::transparent);
    }
}


void InRunGui::setLangStrPtr()
{
    if(langsLwPtr->selectedItems().size() != 0)
    {
        langStrPtr = new QString(langsLwPtr->currentItem()->text() );
    }
    else
    {
        cerr << "Invalid input at InRunGui::setLangStrPtr()" << endl;
    }
}


QString* InRunGui::getLangStrPtr()
{
    return langStrPtr;
}


void InRunGui::setFileTypeStrPtr()
{
    if(fileTypeLwPtr->selectedItems().size() != 0)
    {
        fileTypeStrPtr = new QString(fileTypeLwPtr->currentItem()->text() );
    }
    else
    {
        cerr << "Invalid input at InRunGui::setFileTypeStrPtr()" << endl;
    }
}


QString* InRunGui::getFileTypeStrPtr()
{
    return fileTypeStrPtr;
}


QListWidget* InRunGui::getLangsLwPtr() const
{
    return langsLwPtr;
}


QListWidget* InRunGui::getFileTypeLwPtr() const
{
    return fileTypeLwPtr;
}


void InRunGui::triggerMutators()
{
    setLangStrPtr();
    setFileTypeStrPtr();
}


QString* InRunGui::toString()
{
    QString* tmp = new QString("Language: ");
    tmp->append(getLangStrPtr() );
    tmp->append("\nFile Type: ");
    tmp->append(getFileTypeStrPtr() );
    
    return tmp;
}


InRunGui::~InRunGui()
{
    ;
}
