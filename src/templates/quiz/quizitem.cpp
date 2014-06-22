#include "templates/quiz/quizitem.h"


QuizItem::QuizItem(QWidget *parent) : QWidget(parent), m_ui(new Ui::QuizItem) {
  m_ui->setupUi(this);
  m_answerButtons = QList<QRadioButton*>();
  m_answerButtons.append(m_ui->m_rbAnswerOne);
  m_answerButtons.append(m_ui->m_rbAnswerTwo);
  m_answerButtons.append(m_ui->m_rbAnswerThree);
  m_answerButtons.append(m_ui->m_rbAnswerFour);
}

QuizItem::~QuizItem() {
  delete m_ui;
}

void QuizItem::setQuestion(const QuizQuestion &question, int question_number) {
  m_question = question;

  m_ui->m_rbAnswerOne->setText(question.answerOne());
  m_ui->m_rbAnswerTwo->setText(question.answerTwo());
  m_ui->m_rbAnswerThree->setText(question.answerThree());
  m_ui->m_rbAnswerFour->setText(question.answerFour());

  m_ui->m_rbAnswerOne->setVisible(question.correctAnswer() == 1 || !question.answerOne().simplified().isEmpty());
  m_ui->m_rbAnswerTwo->setVisible(question.correctAnswer() == 2 || !question.answerTwo().simplified().isEmpty());
  m_ui->m_rbAnswerThree->setVisible(question.correctAnswer() == 3 || !question.answerThree().simplified().isEmpty());
  m_ui->m_rbAnswerFour->setVisible(question.correctAnswer() == 4 || !question.answerFour().simplified().isEmpty());

  m_ui->m_rbAnswerOne->setChecked(question.correctAnswer() == 1);
  m_ui->m_rbAnswerTwo->setChecked(question.correctAnswer() == 2);
  m_ui->m_rbAnswerThree->setChecked(question.correctAnswer() == 3);
  m_ui->m_rbAnswerFour->setChecked(question.correctAnswer() == 4);

  m_ui->m_lblQuestionNumber->setText(tr("Question number %1").arg(question_number));
  m_ui->m_lblQuestionText->setText(question.question());
}
