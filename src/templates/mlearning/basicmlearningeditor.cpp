/*
  Copyright (c) 2012, BuildmLearn Contributors listed at http://buildmlearn.org/people/
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of the BuildmLearn nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "templates/mlearning/basicmlearningeditor.h"

#include "miscellaneous/iconfactory.h"


BasicmLearningEditor::BasicmLearningEditor(TemplateCore *core, QWidget *parent)
  : TemplateEditor(core, parent), m_ui(new Ui::BasicmLearningEditor) {
  m_ui->setupUi(this);

  m_ui->m_txtTitle->lineEdit()->setPlaceholderText(tr("Title of the item"));
  m_ui->m_txtDescription->lineEdit()->setPlaceholderText(tr("Description of the item"));

  IconFactory *factory = IconFactory::instance();

  m_ui->m_btnItemAdd->setIcon(factory->fromTheme("item-add"));
  m_ui->m_btnItemRemove->setIcon(factory->fromTheme("item-remove"));
  m_ui->m_btnItemUp->setIcon(factory->fromTheme("move-up"));
  m_ui->m_btnItemDown->setIcon(factory->fromTheme("move-down"));
}

BasicmLearningEditor::~BasicmLearningEditor() {
  delete m_ui;
}

bool BasicmLearningEditor::canGenerateApplications() {
  return false;
}