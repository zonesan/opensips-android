INSERT INTO version (table_name, table_version) values ('dialog','9');
CREATE TABLE dialog (
    dlg_id BIGINT(10) UNSIGNED PRIMARY KEY NOT NULL,
    callid CHAR(255) NOT NULL,
    from_uri CHAR(128) NOT NULL,
    from_tag CHAR(64) NOT NULL,
    to_uri CHAR(128) NOT NULL,
    to_tag CHAR(64) NOT NULL,
    mangled_from_uri CHAR(64) DEFAULT NULL,
    mangled_to_uri CHAR(64) DEFAULT NULL,
    caller_cseq CHAR(11) NOT NULL,
    callee_cseq CHAR(11) NOT NULL,
    caller_ping_cseq INT(11) UNSIGNED NOT NULL,
    callee_ping_cseq INT(11) UNSIGNED NOT NULL,
    caller_route_set TEXT(512),
    callee_route_set TEXT(512),
    caller_contact CHAR(128) NOT NULL,
    callee_contact CHAR(128) NOT NULL,
    caller_sock CHAR(64) NOT NULL,
    callee_sock CHAR(64) NOT NULL,
    state INT(10) UNSIGNED NOT NULL,
    start_time INT(10) UNSIGNED NOT NULL,
    timeout INT(10) UNSIGNED NOT NULL,
    vars BLOB(4096) DEFAULT NULL,
    profiles TEXT(512) DEFAULT NULL,
    script_flags INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    flags INT(10) UNSIGNED DEFAULT 0 NOT NULL
) ENGINE=MyISAM;

