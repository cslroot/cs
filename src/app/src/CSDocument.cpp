#include "CSDocument.h"

#include "CSApp.h"
#include <cs/base.h>
#include <cs/core.h>
#include <cs/modeler.h>

#include <cassert>
#include <chrono>
#include <fstream>
#include <sqlite3.h>

// #include <filesystem>
// using fs = std::filesystem;

using namespace cs::app;
using namespace cs::base;
using namespace cs::modeler;

namespace {
sqlite3*
create_db_doc()
{
  sqlite3* db = nullptr;
  auto rc = sqlite3_open(":memory:", &db);
  assert(rc == SQLITE_OK);

  char* err = nullptr;
  rc = sqlite3_exec(
    db,
    "CREATE TABLE hoge(id INTEGER, name TEXT, category TEXT, "
    "cost INTEGER, size INTEGER, weight INTEGER, createed_at DATETIME);",
    NULL,
    NULL,
    &err);
  assert(rc == SQLITE_OK);
  if (rc != SQLITE_OK) {
    printf("Execution Err \n");
    sqlite3_close(db);
    sqlite3_free(err);
    return nullptr;
  }
  rc = sqlite3_exec(db,
                    "CREATE TABLE entities("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "enttype TEXT);",
                    NULL,
                    NULL,
                    &err);
  assert(rc == SQLITE_OK);
  if (rc != SQLITE_OK) {
    printf("Execution Err \n");
    CSApp::Instance().Log().Error(err);
    sqlite3_close(db);
    sqlite3_free(err);
    return nullptr;
  }

  return db;
}

void
OnCreateEntity(cs::core::CSObject* ent)
{}
void
OnDeleteEntity(cs::core::CSObject* ent)
{}
void
OnUpdateEntity(cs::core::CSObject* ent)
{}

}

/**
 * @brief data to save/restore
 *
 */
struct DocumentData
{
  CSString _name;
  std::chrono::system_clock::time_point current =
    std::chrono::system_clock::now();
};

struct CSDocument::Impl
{
  DocumentData _data;
  CSString _filepath;

  cs::modeler::CSModeler _modeler;

  sqlite3* _db;

  void SaveAs(const CSString& filepath)
  {
    sqlite3* pDbTargetInMemory = _db;
    sqlite3* pDbFile;        /* Database connection opened on zFilename */
    sqlite3_backup* pBackup; /* Backup object used to copy data */

    /* Open the database file identified by zFilename. Exit early if this
     *fails
     ** for any reason. */
    auto rc = sqlite3_open(filepath.c_str(), &pDbFile);
    if (rc == SQLITE_OK) {
      /* Set up the backup procedure to copy from the "main" database of
      ** connection pFile to the main database of connection pInMemory.
      ** If something goes wrong, pBackup will be set to NULL and an error
      ** code and message left in connection pTo.
      **
      ** If the backup object is successfully created, call backup_step()
      ** to copy data from pFile to pInMemory. Then call backup_finish()
      ** to release resources associated with the pBackup object.  If an
      ** error occurred, then an error code and message will be left in
      ** connection pTo. If no error occurred, then the error code belonging
      ** to pTo is set to SQLITE_OK.
      */
      pBackup = sqlite3_backup_init(pDbFile, "main", pDbTargetInMemory, "main");
      if (pBackup) {
        (void)sqlite3_backup_step(pBackup, -1);
        (void)sqlite3_backup_finish(pBackup);
      }
      rc = sqlite3_errcode(pDbFile);
    }

    (void)sqlite3_close(pDbFile);
  }
};

CSDocument::CSDocument(CSFactory::Key)
  : _impl(std::make_unique<Impl>())
{
  _impl->_db = create_db_doc();

  char* err = nullptr;
  auto rc =
    sqlite3_exec(_impl->_db,
                 "insert into hoge values(1, 'AAA', 'aaa', 10, 100, 111, "
                 "CURRENT_TIMESTAMP);",
                 NULL,
                 NULL,
                 &err);
  assert(rc == SQLITE_OK);
}

CSDocument::~CSDocument()
{
  sqlite3_close(_impl->_db);
}

void
CSDocument::SaveAs(const cs::base::CSString& filepath)
{
  _impl->SaveAs(filepath);

  // std::ofstream ofs(filepath.c_str());
  // ofs << "hoge" << std::endl;
  // // ofs << "name: " << Name() << std::endl;
  // ofs.close();

  _impl->_filepath = filepath;
}

cs::modeler::CSModeler&
CSDocument::Modeler() const
{
  return _impl->_modeler;
}
